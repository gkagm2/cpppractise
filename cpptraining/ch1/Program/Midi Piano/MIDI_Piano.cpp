// 코드 출처 https://www.youtube.com/watch?time_continue=2738&v=jq08L2TxY4E&feature=emb_logo

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

#define NKEY 127

// link : https://docs.microsoft.com/en-us/windows/win32/multimedia/midi-reference
// winmm.lib 파일을 링크할때 추가
#pragma comment(lib,"winmm.lib") 


// 선언되는 구조체를 1바이트 단위로 정렬
#pragma pack(push, 1) // 1byte씩 정렬

// https://www.midi.org/specifications-old/item/table-2-expanded-messages-list-status-bytes
// https://www.midi.org/specifications-old/item/table-3-control-change-messages-data-bytes-2

// Short Midi MSG 구조체
typedef struct {
	BYTE byteState;
	BYTE bytebyteNote;
	BYTE byteVelocity;
	BYTE byteNote;
	BYTE byteNULL;
}MIDIShortMSG_ST;


// MIDIShortMSG_ST 구조체의 값을 DWORD(unsigned long)로 변환할 때 사용하는 공용체
typedef union {
	DWORD dwMIDIData;
	MIDIShortMSG_ST stMIDIData;
}MIDIShortMSG;

// 원래의 구조체 정렬 방식으로 변경
#pragma pack(pop)

// 미디 출력 중에 발생하는 메시지를 받는 콜백함수.
void CALLBACK MidiOutProc(HMIDIOUT hMidDevice, UINT uMsg, DWORD Instance, DWORD Param1, DWORD Param2) {

}

// 미디 에러 코드를 문자열로 출력하는 함수
void MIDIOutputError(MMRESULT mmResult) {
	LPTSTR szErrMsg[129]; // 에러 문자열을 저장할 배열

	// 에러 코드를 문자열로 변환
	midiInGetErrorText(mmResult, *szErrMsg, sizeof(szErrMsg));

	// 변환된 문자열을 메시지 박스로 출력
	MessageBox(0, *szErrMsg, L"Midi Error!", MB_OK);
}

void PrintPiano() {
	puts("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  | ");
	puts("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  | ");
	puts("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  | ");
	puts("|  |s| |d|  |  |g| |h| |j|  |  |2| |3|  |  |5| |6| |7|  |  |9| |0|  | ");
	puts("|  └─┘ └─┘  |  └─┘ └─┘ └─┘  |  └─┘ └─┘  |  └─┘ └─┘ └─┘  |  └─┘ └─┘  | ");
	puts("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   | ");
	puts("| z | x | c | v | b | n | m | q | w | e | r | t | y | u | i | o | p | ");
	puts("└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘ ");
}

// 미디 장치 번호를 알아 내는 함수
long MIDIGetDevID(HMIDIOUT hMidiDevice) {
	UINT uDeviceID; //장치 번호 저장 변수

	// 미디 출력 핸들에 대응하는 장치 번호를 uDeviceID 변수에 저장
	MMRESULT mmResult = midiOutGetID(hMidiDevice, &uDeviceID);

	// 장치 조사중에 에러가 발생할 경우
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult); // 에러 출력 후 에러를 리턴값으로 알림
		return -1;
	}

	// 장치 번호 리턴
	return (long)uDeviceID;
}

// 미디 핸들로 미디 장치 속성을 MIDIOUTCPAS 구조체 변수에 저장해주는 변수
void MIDIGetDevCaps(HMIDIOUT hMidiDevice, MIDIOUTCAPS *Caps){
	long lDeviceID;		// 장치 번호 저장 변수
	MMRESULT mmResult;	// 에러 코드 저장 변수

	// 미디 핸들을 이용해 장치 번호를 조사해서 lDeviceID 변수에 저장
	lDeviceID = MIDIGetDevID(hMidiDevice);

	// lDeviceID가 음수면 에러가 난 경우이므로 이 함수의 처리르 더이상 진행하지 않는다.
	if (lDeviceID < 0)
		return;

	// 미디 장치의 속성을 MIDIOUTCAPS 구조체 변수에 저장
	mmResult = midiOutGetDevCaps((UINT)lDeviceID, Caps, sizeof(MIDIOUTCAPS));

	// 에러 문자열 출력
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult);
	}
}

// 장치 번호에 해당하는 미디 장치 열기
HMIDIOUT MIDIOpen(WORD wMidiNum) {
	WORD wMidiMax = 0;
	MMRESULT mmResult = 0;
	HMIDIOUT hMidiDevice = NULL;

	// 사용가능한 장치의 총 갯수를 wMidiMax변수에 저장
	wMidiMax = midiInGetNumDevs();

	// 입력한 번호가 총 갯수보다 같거나 큰 값이면 장치 번호를 0으로 조정
	if (wMidiNum >= wMidiMax)
		wMidiNum = 0;

	// wMidiMax변수 값에 해당하는 미디장치를 열고 장치 핸들값을 hMidiDevice
	// 연주 중에 발생하는 메시지는 콜백함수 MidiOutProc로 보냄
	mmResult = midiOutOpen(&hMidiDevice, wMidiNum, (DWORD)(MidiOutProc), (DWORD)NULL, CALLBACK_FUNCTION);

	// 열기 도중 에러가 발생하면
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult); // 에러문자열 출력
		return NULL;
	}

	return hMidiDevice; // 장치 핸들 리턴
}

// 핸들값에 해당하는 미디장치 닫기
LRESULT MIDIClose(HMIDIOUT hMidiDevice) {
	MMRESULT mmResult;

	// 미디 핸들값을 이용해 장치 닫기
	mmResult = midiOutClose(hMidiDevice);
	
	// 닫는 도중에 에러가 발생하면
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult); // 에러 출력
		return FALSE; // 닫기 실패
	}

	return TRUE; // 닫기 성공
}

// 짧은 미디 메시지를 미지 장치로 보내는 함수
void MIDISendShortMsg(HMIDIOUT hMidiDevice, BYTE byteState, BYTE byteNote, BYTE byteValo) {
	MIDIShortMSG sMsg;

	// MIDIShortMSG 구조체 안에 있는 MIDIShortMSG_ST 구조체 변수의 각 멤버 변수에 값을 채움
	sMsg.stMIDIData.byteVelocity = byteValo;
	sMsg.stMIDIData.byteNote= byteNote;
	sMsg.stMIDIData.byteState = byteState;
	sMsg.stMIDIData.byteNULL = 0;

	// 출력 장치로 값을 채워넣은 구조체의 데이터를 보냄
	midiOutShortMsg(hMidiDevice, sMsg.dwMIDIData);
}

// 모든 채널의 연주중인 음을 종료시키는 함수
void MIDIAllChannelSoundOff(HMIDIOUT hMidiDevice) {
	BYTE channel;

	for (channel = 0; channel < 16; ++channel) {
		// 0xB0 : Control/Mode Change
		// 0x78 : All Sound Off
		MIDISendShortMsg(hMidiDevice, (BYTE)(0xB0 + channel), 0x78, 0);
	}
}


int main() {
	int loop;
	BYTE key = 0;
	BYTE volume = 127;  // 볼륨 (max = 127)
	BYTE octave = 48;	// 옥타브 : 48 (default)
	BYTE velocity = 120;// 키 속도 : 120 (default)

	HMIDIOUT hMidiDevice; // 미디장치 컨트롤을 위한 미디 출력 핸들

	// 피아노 건반으로 매칭할 키보드 키
	BYTE pianoKey[NKEY] = {
		0x5A, 0x53, 0x58, 0x44, 0x43,				// Z S X D C
		0x56, 0x47, 0x42, 0x89, 0x4E, 0x4A, 0X4D,	// V G B H N J M
		0X51, 0X32, 0X57, 0X33, 0X45,				// Q 2 W 3 E 
		0X52, 0X35, 0X54, 0X36, 0X59, 0X37, 0X55,	// R 5 T 6 Y 7 U
		0X49, 0X39, 0X4F, 0X30, 0X50				// I 9 O 0 P 
	};

	BYTE pianoKeyOnOff[NKEY] = { 0 };

	hMidiDevice = MIDIOpen(0);

	if (hMidiDevice == NULL)
		return 0;

	// 파이노 화면 출력
	PrintPiano();

	// 모든 채널의 소리 끄기
	MIDIAllChannelSoundOff(hMidiDevice);
	
	// 1번 채널의 볼륨을 127로 세팅(0 ~ 127)
	// 0xB0: Control/Mode Change
	// 7 : Channel Volume MS
	MIDISendShortMsg(hMidiDevice, 0xB0, 7, volume);

	loop = 1;
	while (loop) { // loop변수가 0이 아니면 계속 반복
		//ESC Key : loop변수 값 0(종료)
		if (GetKeyState(VK_ESCAPE) < 0)
			loop = 0;

		// Keyboard Piano Key
		else {
			for (key = 0; key < NKEY; ++key) {
				// szMusKey배열을 i번째 값에 해당하는 키가 입력되면
				if (GetKeyState(pianoKey[key]) < 0) {
					// 이전에 이 키를 누른 적이 없다면
					if(pianoKeyOnOff[key] == 0) {
						// 이전에 이 키가 눌렀던 것으로 기록
						pianoKeyOnOff[key] = 1;
						// 현재 눌린 키에 해당하는 미디 음을 연주
						// 0x90 : Note on
						MIDISendShortMsg(hMidiDevice, 0x90, (BYTE)(octave + key), velocity);
					}
				}
			}
		}

		// 키보드 키를 떼었을때
		for (key = 0; key < NKEY; ++key) {
			//szMusKey배열의 i번째 값에 해당하는 키가 입력된 것이 아니라면
			if (!(GetKeyState(pianoKey[key] < 0))) {
				// 그 키가 입력된 적이 있는 키이면
				if (pianoKeyOnOff[key] != 0) {
					// 누른 적이 없는 걸로 기록
					pianoKeyOnOff[key] = 0;
					// 연주 중인 소리를 끔
					// 0x80: Note off
					MIDISendShortMsg(hMidiDevice, 0x80, (BYTE)(octave + key), velocity);
				}
			}
		}

		// ESC로 나가면 현재 연주중인 소리를 모두 끔
		for (key = 0; key < NKEY; ++key) {
			if (pianoKeyOnOff[key] != 0) {
				MIDISendShortMsg(hMidiDevice, 0x80, (BYTE)(octave + key), velocity);
			}
		}

		// 모든 채널 사운드 끄기
		MIDIAllChannelSoundOff(hMidiDevice);

		// 열린 미디 장치를 닫기
		MIDIClose(hMidiDevice); 
	}


	return 0;
}
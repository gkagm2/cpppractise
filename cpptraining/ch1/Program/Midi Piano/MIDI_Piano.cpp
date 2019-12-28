// �ڵ� ��ó https://www.youtube.com/watch?time_continue=2738&v=jq08L2TxY4E&feature=emb_logo

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

#define NKEY 127

// link : https://docs.microsoft.com/en-us/windows/win32/multimedia/midi-reference
// winmm.lib ������ ��ũ�Ҷ� �߰�
#pragma comment(lib,"winmm.lib") 


// ����Ǵ� ����ü�� 1����Ʈ ������ ����
#pragma pack(push, 1) // 1byte�� ����

// https://www.midi.org/specifications-old/item/table-2-expanded-messages-list-status-bytes
// https://www.midi.org/specifications-old/item/table-3-control-change-messages-data-bytes-2

// Short Midi MSG ����ü
typedef struct {
	BYTE byteState;
	BYTE bytebyteNote;
	BYTE byteVelocity;
	BYTE byteNote;
	BYTE byteNULL;
}MIDIShortMSG_ST;


// MIDIShortMSG_ST ����ü�� ���� DWORD(unsigned long)�� ��ȯ�� �� ����ϴ� ����ü
typedef union {
	DWORD dwMIDIData;
	MIDIShortMSG_ST stMIDIData;
}MIDIShortMSG;

// ������ ����ü ���� ������� ����
#pragma pack(pop)

// �̵� ��� �߿� �߻��ϴ� �޽����� �޴� �ݹ��Լ�.
void CALLBACK MidiOutProc(HMIDIOUT hMidDevice, UINT uMsg, DWORD Instance, DWORD Param1, DWORD Param2) {

}

// �̵� ���� �ڵ带 ���ڿ��� ����ϴ� �Լ�
void MIDIOutputError(MMRESULT mmResult) {
	LPTSTR szErrMsg[129]; // ���� ���ڿ��� ������ �迭

	// ���� �ڵ带 ���ڿ��� ��ȯ
	midiInGetErrorText(mmResult, *szErrMsg, sizeof(szErrMsg));

	// ��ȯ�� ���ڿ��� �޽��� �ڽ��� ���
	MessageBox(0, *szErrMsg, L"Midi Error!", MB_OK);
}

void PrintPiano() {
	puts("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  | ");
	puts("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  | ");
	puts("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  | ");
	puts("|  |s| |d|  |  |g| |h| |j|  |  |2| |3|  |  |5| |6| |7|  |  |9| |0|  | ");
	puts("|  ������ ������  |  ������ ������ ������  |  ������ ������  |  ������ ������ ������  |  ������ ������  | ");
	puts("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   | ");
	puts("| z | x | c | v | b | n | m | q | w | e | r | t | y | u | i | o | p | ");
	puts("������������������������������������������������������������������������������������������������������������������������������������������ ");
}

// �̵� ��ġ ��ȣ�� �˾� ���� �Լ�
long MIDIGetDevID(HMIDIOUT hMidiDevice) {
	UINT uDeviceID; //��ġ ��ȣ ���� ����

	// �̵� ��� �ڵ鿡 �����ϴ� ��ġ ��ȣ�� uDeviceID ������ ����
	MMRESULT mmResult = midiOutGetID(hMidiDevice, &uDeviceID);

	// ��ġ �����߿� ������ �߻��� ���
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult); // ���� ��� �� ������ ���ϰ����� �˸�
		return -1;
	}

	// ��ġ ��ȣ ����
	return (long)uDeviceID;
}

// �̵� �ڵ�� �̵� ��ġ �Ӽ��� MIDIOUTCPAS ����ü ������ �������ִ� ����
void MIDIGetDevCaps(HMIDIOUT hMidiDevice, MIDIOUTCAPS *Caps){
	long lDeviceID;		// ��ġ ��ȣ ���� ����
	MMRESULT mmResult;	// ���� �ڵ� ���� ����

	// �̵� �ڵ��� �̿��� ��ġ ��ȣ�� �����ؼ� lDeviceID ������ ����
	lDeviceID = MIDIGetDevID(hMidiDevice);

	// lDeviceID�� ������ ������ �� ����̹Ƿ� �� �Լ��� ó���� ���̻� �������� �ʴ´�.
	if (lDeviceID < 0)
		return;

	// �̵� ��ġ�� �Ӽ��� MIDIOUTCAPS ����ü ������ ����
	mmResult = midiOutGetDevCaps((UINT)lDeviceID, Caps, sizeof(MIDIOUTCAPS));

	// ���� ���ڿ� ���
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult);
	}
}

// ��ġ ��ȣ�� �ش��ϴ� �̵� ��ġ ����
HMIDIOUT MIDIOpen(WORD wMidiNum) {
	WORD wMidiMax = 0;
	MMRESULT mmResult = 0;
	HMIDIOUT hMidiDevice = NULL;

	// ��밡���� ��ġ�� �� ������ wMidiMax������ ����
	wMidiMax = midiInGetNumDevs();

	// �Է��� ��ȣ�� �� �������� ���ų� ū ���̸� ��ġ ��ȣ�� 0���� ����
	if (wMidiNum >= wMidiMax)
		wMidiNum = 0;

	// wMidiMax���� ���� �ش��ϴ� �̵���ġ�� ���� ��ġ �ڵ鰪�� hMidiDevice
	// ���� �߿� �߻��ϴ� �޽����� �ݹ��Լ� MidiOutProc�� ����
	mmResult = midiOutOpen(&hMidiDevice, wMidiNum, (DWORD)(MidiOutProc), (DWORD)NULL, CALLBACK_FUNCTION);

	// ���� ���� ������ �߻��ϸ�
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult); // �������ڿ� ���
		return NULL;
	}

	return hMidiDevice; // ��ġ �ڵ� ����
}

// �ڵ鰪�� �ش��ϴ� �̵���ġ �ݱ�
LRESULT MIDIClose(HMIDIOUT hMidiDevice) {
	MMRESULT mmResult;

	// �̵� �ڵ鰪�� �̿��� ��ġ �ݱ�
	mmResult = midiOutClose(hMidiDevice);
	
	// �ݴ� ���߿� ������ �߻��ϸ�
	if (mmResult != MMSYSERR_NOERROR) {
		MIDIOutputError(mmResult); // ���� ���
		return FALSE; // �ݱ� ����
	}

	return TRUE; // �ݱ� ����
}

// ª�� �̵� �޽����� ���� ��ġ�� ������ �Լ�
void MIDISendShortMsg(HMIDIOUT hMidiDevice, BYTE byteState, BYTE byteNote, BYTE byteValo) {
	MIDIShortMSG sMsg;

	// MIDIShortMSG ����ü �ȿ� �ִ� MIDIShortMSG_ST ����ü ������ �� ��� ������ ���� ä��
	sMsg.stMIDIData.byteVelocity = byteValo;
	sMsg.stMIDIData.byteNote= byteNote;
	sMsg.stMIDIData.byteState = byteState;
	sMsg.stMIDIData.byteNULL = 0;

	// ��� ��ġ�� ���� ä������ ����ü�� �����͸� ����
	midiOutShortMsg(hMidiDevice, sMsg.dwMIDIData);
}

// ��� ä���� �������� ���� �����Ű�� �Լ�
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
	BYTE volume = 127;  // ���� (max = 127)
	BYTE octave = 48;	// ��Ÿ�� : 48 (default)
	BYTE velocity = 120;// Ű �ӵ� : 120 (default)

	HMIDIOUT hMidiDevice; // �̵���ġ ��Ʈ���� ���� �̵� ��� �ڵ�

	// �ǾƳ� �ǹ����� ��Ī�� Ű���� Ű
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

	// ���̳� ȭ�� ���
	PrintPiano();

	// ��� ä���� �Ҹ� ����
	MIDIAllChannelSoundOff(hMidiDevice);
	
	// 1�� ä���� ������ 127�� ����(0 ~ 127)
	// 0xB0: Control/Mode Change
	// 7 : Channel Volume MS
	MIDISendShortMsg(hMidiDevice, 0xB0, 7, volume);

	loop = 1;
	while (loop) { // loop������ 0�� �ƴϸ� ��� �ݺ�
		//ESC Key : loop���� �� 0(����)
		if (GetKeyState(VK_ESCAPE) < 0)
			loop = 0;

		// Keyboard Piano Key
		else {
			for (key = 0; key < NKEY; ++key) {
				// szMusKey�迭�� i��° ���� �ش��ϴ� Ű�� �ԷµǸ�
				if (GetKeyState(pianoKey[key]) < 0) {
					// ������ �� Ű�� ���� ���� ���ٸ�
					if(pianoKeyOnOff[key] == 0) {
						// ������ �� Ű�� ������ ������ ���
						pianoKeyOnOff[key] = 1;
						// ���� ���� Ű�� �ش��ϴ� �̵� ���� ����
						// 0x90 : Note on
						MIDISendShortMsg(hMidiDevice, 0x90, (BYTE)(octave + key), velocity);
					}
				}
			}
		}

		// Ű���� Ű�� ��������
		for (key = 0; key < NKEY; ++key) {
			//szMusKey�迭�� i��° ���� �ش��ϴ� Ű�� �Էµ� ���� �ƴ϶��
			if (!(GetKeyState(pianoKey[key] < 0))) {
				// �� Ű�� �Էµ� ���� �ִ� Ű�̸�
				if (pianoKeyOnOff[key] != 0) {
					// ���� ���� ���� �ɷ� ���
					pianoKeyOnOff[key] = 0;
					// ���� ���� �Ҹ��� ��
					// 0x80: Note off
					MIDISendShortMsg(hMidiDevice, 0x80, (BYTE)(octave + key), velocity);
				}
			}
		}

		// ESC�� ������ ���� �������� �Ҹ��� ��� ��
		for (key = 0; key < NKEY; ++key) {
			if (pianoKeyOnOff[key] != 0) {
				MIDISendShortMsg(hMidiDevice, 0x80, (BYTE)(octave + key), velocity);
			}
		}

		// ��� ä�� ���� ����
		MIDIAllChannelSoundOff(hMidiDevice);

		// ���� �̵� ��ġ�� �ݱ�
		MIDIClose(hMidiDevice); 
	}


	return 0;
}
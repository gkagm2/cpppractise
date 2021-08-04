#include <iostream>
#include <stack>
#include <memory>
using namespace std;

// Command Interface
class ICommand {
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};

// Model

class Tv {
private:
	bool m_bOn;
	int m_iChannel;

public:
	void SwitchOn() { m_bOn = true; }
	void SwitchOff() { m_bOn = false; }
	void SwitchChannel(int _iChannel) { m_iChannel = _iChannel; }

	bool IsOn() { return m_bOn; }
	int GetChannel() { return m_iChannel; }

public:
	Tv() : 
		m_bOn(false),
		m_iChannel(0)
	{}
	virtual ~Tv() {}
};

class TvOnCommand : public ICommand {
private:
	Tv* m_pTv;

public:
	virtual void Execute() override { m_pTv->SwitchOn(); }
	virtual void Undo() override { m_pTv->SwitchOff(); }
	virtual void Redo() override { m_pTv->SwitchOn(); }

public:
	TvOnCommand(Tv& _tv) :
		m_pTv(&_tv)
	{}
	virtual ~TvOnCommand() {}
};

class TvOffCommand : public ICommand {
private:
	TvOnCommand m_TvOnCommand;
public:
	virtual void Execute() override { m_TvOnCommand.Undo(); } // switch off
	virtual void Undo() override { m_TvOnCommand.Execute(); } // switch on
	virtual void Redo() override { m_TvOnCommand.Undo(); }	  // switch off

public:
	TvOffCommand(Tv& _tv) :
		m_TvOnCommand(_tv)
	{}
	virtual ~TvOffCommand() {}
};

class TvSwitchChannelCommend : public ICommand {
private:
	Tv* m_pTv;
	int m_iOldChannel;
	int m_iNewChannel;

public:
	virtual void Execute() override {
		m_iOldChannel = m_pTv->GetChannel();
		m_pTv->SwitchChannel(m_iNewChannel);
	}
	virtual void Undo() override { 
		m_pTv->SwitchChannel(m_iOldChannel);
	}
	virtual void Redo() override {
		m_pTv->SwitchChannel(m_iNewChannel);
	}

public:
	TvSwitchChannelCommend(Tv* _tv, int _iChannel) :
		m_pTv(_tv),
		m_iNewChannel(_iChannel)
	{};
	virtual ~TvSwitchChannelCommend() {};
};

// Controller Undo, Redo
typedef stack<shared_ptr<ICommand>> commandStack_t;

class CommandManager {
private:
	commandStack_t m_stkUndo;
	commandStack_t m_stkRedo;

public:
	void ExecuteCmd(shared_ptr<ICommand> _pCommand) {
		m_stkRedo = commandStack_t(); // clear the stack
		_pCommand->Execute();
		m_stkUndo.push(_pCommand);
	}

	void Undo() {
		if (m_stkUndo.empty())
			return;

		m_stkUndo.top()->Undo();
		m_stkRedo.push(m_stkUndo.top());
		m_stkUndo.pop();
	}

	void Redo() {
		if (m_stkRedo.empty())
			return;

		m_stkRedo.top()->Redo();
		m_stkUndo.push(m_stkRedo.top());
		m_stkRedo.pop();
	}


public:
	CommandManager() {}
	virtual ~CommandManager() {}
};


int main() {

	Tv tv;
	CommandManager cmdMgr;


	cout << "tv state :" << tv.IsOn() << "\n";

	shared_ptr<ICommand> tvon(new TvOnCommand(tv));
	cmdMgr.ExecuteCmd(tvon);
	cout << "after command tv state : " << tv.IsOn() << "\n";

	shared_ptr<ICommand> c1(new TvSwitchChannelCommend(&tv, 1));
	cmdMgr.ExecuteCmd(c1);
	cout << "switched to channel " << tv.GetChannel() << "\n";

	shared_ptr<ICommand> c2(new TvSwitchChannelCommend(&tv, 2));
	cmdMgr.ExecuteCmd(c2);
	cout << "switched to channel " << tv.GetChannel() << "\n";

	shared_ptr<ICommand> c3(new TvSwitchChannelCommend(&tv, 3));
	cmdMgr.ExecuteCmd(c3);
	cout << "switched to channel " << tv.GetChannel() << "\n";

	cout << "\nCurrent Chanel : " << tv.GetChannel() << "\n\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "redoing\n";
	cmdMgr.Redo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "redoing\n";
	cmdMgr.Redo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "redoing\n";
	cmdMgr.Redo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";

	cout << "undoing\n";
	cmdMgr.Undo();
	cout << "Current Chanel : " << tv.GetChannel() << "\n";
	cout << "TvState : " << tv.IsOn() << "\n";


	return 0;
}
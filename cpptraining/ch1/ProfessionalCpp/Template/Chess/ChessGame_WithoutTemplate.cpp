#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;

// Template 없이 Grid 클래스 만듬.

class GamePiece {
public:
	virtual std::unique_ptr<GamePiece> clone() const =0;
};

class ChessPiece : public GamePiece {
public:
	virtual std::unique_ptr<GamePiece> clone() const override;
};

std::unique_ptr<GamePiece>  ChessPiece::clone() const {
	// 이 인스턴스를 복사하기 위해 복제 생성자를 호출한다.
	return std::make_unique<ChessPiece>(*this);
}

class GameBoard {
private:
	size_t mWidth;
	size_t mHeight;
	std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
	void copyFrom(const GameBoard& src);
	void initializeCellsContainer();

public:
	static const size_t kDefaultWidth = 0;
	static const size_t kDefaultHeight = 0;

public:
	explicit GameBoard(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	GameBoard(const GameBoard& src); // 복제 생성자
	virtual ~GameBoard();
	GameBoard& operator=(const GameBoard& rhs); // 대입 연산자

	// 말을 특정 위치에 둔다. 이때부터 GameBoard가 그 말을 소유하게 된다.
	// 특정 위치의 말을 없애고 싶으면 inPiece의 값으로 nullptr을 넘긴다.
	void setPieceAt(size_t x, size_t y, std::unique_ptr<GamePiece> inPiece);
	std::unique_ptr<GamePiece>& getPieceAt(size_t x, size_t y); // 그냥 참조 리턴
	const std::unique_ptr<GamePiece>& getPieceAt(size_t x, size_t y) const; // const 참조 리턴

	size_t GetWidth() const { return mWidth; }
	size_t GetHeight() const { return mHeight; }
};
void GameBoard::copyFrom(const GameBoard & src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	initializeCellsContainer();
	for (size_t i = 0; i < mWidth; ++i) {
		for (size_t j = 0; j < mHeight; ++j) {
			if (src.mCells[i][j])
				mCells[i][j] = src.mCells[i][j]->clone(); // 복사 생성자를 받아야 함. 안그럼 못받음
			else
				mCells[i][j].reset();
		}
	}
}
void GameBoard::initializeCellsContainer()
{
	mCells.resize(mWidth);
	for (auto& column : mCells)
		column.resize(mHeight);
}
GameBoard::GameBoard(size_t inWidth, size_t inHeight) {
	initializeCellsContainer();
}
GameBoard::GameBoard(const GameBoard& src) {
	copyFrom(src);
}
GameBoard::~GameBoard() {
	// vector 스스로 메모리 해제를 하기 때문에 특별히 할 일이 없음.
}
GameBoard& GameBoard::operator=(const GameBoard& rhs) {
	// 자기(self) 대입 여부 검사
	if (this == &rhs)
		return *this;

	// 인자로 주어진 GameBoard를 복제
	copyFrom(rhs);
	return *this;
}

void GameBoard::setPieceAt(size_t x, size_t y, std::unique_ptr<GamePiece> inPiece) {
	mCells[x][y] = std::move(inPiece);
}

std::unique_ptr<GamePiece>& GameBoard::getPieceAt(size_t x, size_t y)
{
	return mCells[x][y];
}

const std::unique_ptr<GamePiece>& GameBoard::getPieceAt(size_t x, size_t y) const
{
	return mCells[x][y];
}

int main() {

	GameBoard chessBoard(8, 8);
	auto pawn = std::make_unique<ChessPiece>();
	chessBoard.setPieceAt(0, 0, std::move(pawn));
	chessBoard.setPieceAt(0, 1, std::make_unique<ChessPiece>());
	chessBoard.setPieceAt(0, 1, nullptr);

	return 0;
}
#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;

// Template ���� Grid Ŭ���� ����.

class GamePiece {
public:
	virtual std::unique_ptr<GamePiece> clone() const =0;
};

class ChessPiece : public GamePiece {
public:
	virtual std::unique_ptr<GamePiece> clone() const override;
};

std::unique_ptr<GamePiece>  ChessPiece::clone() const {
	// �� �ν��Ͻ��� �����ϱ� ���� ���� �����ڸ� ȣ���Ѵ�.
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
	GameBoard(const GameBoard& src); // ���� ������
	virtual ~GameBoard();
	GameBoard& operator=(const GameBoard& rhs); // ���� ������

	// ���� Ư�� ��ġ�� �д�. �̶����� GameBoard�� �� ���� �����ϰ� �ȴ�.
	// Ư�� ��ġ�� ���� ���ְ� ������ inPiece�� ������ nullptr�� �ѱ��.
	void setPieceAt(size_t x, size_t y, std::unique_ptr<GamePiece> inPiece);
	std::unique_ptr<GamePiece>& getPieceAt(size_t x, size_t y); // �׳� ���� ����
	const std::unique_ptr<GamePiece>& getPieceAt(size_t x, size_t y) const; // const ���� ����

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
				mCells[i][j] = src.mCells[i][j]->clone(); // ���� �����ڸ� �޾ƾ� ��. �ȱ׷� ������
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
	// vector ������ �޸� ������ �ϱ� ������ Ư���� �� ���� ����.
}
GameBoard& GameBoard::operator=(const GameBoard& rhs) {
	// �ڱ�(self) ���� ���� �˻�
	if (this == &rhs)
		return *this;

	// ���ڷ� �־��� GameBoard�� ����
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
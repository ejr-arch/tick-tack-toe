// Glue between the HTML board and the C game logic compiled to WebAssembly.
//
// The C side owns the board state. We only keep the Board* pointer here and
// read the nine cells straight out of the module's linear memory.

const CELL_COUNT = 9;

const statusEl = document.getElementById('status');
const resetBtn = document.getElementById('reset');

const cells = [];
for (let i = 1; i <= CELL_COUNT; i++) {
	cells.push(document.getElementById('cell' + i));
}

let module;
let board;
let player = 'X';
let gameOver = false;

const INPUT_OCCUPIED = 0;
const INPUT_OK = 1;
const INPUT_OUT_OF_RANGE = 2;

const GAME_WON = 0;
const GAME_DRAW = 1;
const GAME_PLAYING = 2;

function cellsFromBoard() {
	return Array.from(module.HEAP8.subarray(board, board + CELL_COUNT));
}

function renderBoard() {
	const state = cellsFromBoard();
	for (let i = 0; i < CELL_COUNT; i++) {
		const mark = state[i];
		cells[i].textContent = mark === ' '.charCodeAt(0) || mark === 0 ? String(i + 1) : String.fromCharCode(mark);
	}
}

function disableBoard(disabled) {
	for (const cell of cells) cell.disabled = disabled;
}

function setStatus(text) {
	statusEl.textContent = text;
}

function newGame() {
	if (board) module._gameClose(board);

	board = module._createBoard();
	player = 'X';
	gameOver = false;

	renderBoard();
	disableBoard(false);
	resetBtn.disabled = false;
	setStatus("Player X's turn");
}

function handleClick(position) {
	if (gameOver) return;

	const check = module._checkInput(board, position);

	if (check === INPUT_OUT_OF_RANGE) {
		setStatus('input out of range, try again!!');
		return;
	}

	if (check === INPUT_OCCUPIED) {
		setStatus('position occupied already, try again!!');
		return;
	}

	module._play(board, player.charCodeAt(0), position);

	const state = module._checkGameState(board);

	if (state === GAME_WON) {
		renderBoard();
		disableBoard(true);
		setStatus('PLAYER ' + player + ' WINS');
		gameOver = true;
		return;
	}

	if (state === GAME_DRAW) {
		renderBoard();
		disableBoard(true);
		setStatus('GAME IS A DRAW');
		gameOver = true;
		return;
	}

	player = String.fromCharCode(module._nextPlayer(player.charCodeAt(0)));
	renderBoard();
	setStatus("Player " + player + "'s turn");
}

cells.forEach((cell, index) => {
	cell.addEventListener('click', () => handleClick(index + 1));
});

resetBtn.addEventListener('click', newGame);

// Keep the board inert until the wasm engine is ready.
disableBoard(true);
resetBtn.disabled = true;

createTicTacToeModule()
	.then((m) => {
		module = m;
		newGame();
	})
	.catch((err) => {
		console.error(err);
		setStatus('Failed to load the game engine: ' + err);
	});

#!/usr/bin/env bash
# Build the tic-tac-toe core logic (../game.c) into a WebAssembly module
# and emit the JS loader used by main.js.
set -euo pipefail

cd "$(dirname "$0")"

emcc ../game.c -o game.js \
	--no-entry \
	-O2 \
	-sMODULARIZE=1 \
	-sEXPORT_NAME=createTicTacToeModule \
	-sEXPORTED_FUNCTIONS='["_createBoard","_play","_checkInput","_checkGameState","_nextPlayer","_gameClose"]' \
	-sEXPORTED_RUNTIME_METHODS='["cwrap","HEAP8"]'

echo "Built game.js + game.wasm"

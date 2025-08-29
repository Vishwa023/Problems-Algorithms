import { Jumper } from "./jumper.class";
import { Player } from "./player.class";
import { Dice } from "./dice.class";
import { GameBoard } from "./gameBoard.class";

function main() {
    const size = 100;
    const dice = new Dice(6);
    const players: Player[] = [
        new Player("Player 1", 1),
        new Player("Player 2", 2),
        new Player("Player 3", 3),
        new Player("Player 4", 4),
        new Player("Player 5", 5),
    ];
    const snakes = [
        new Jumper(20, 5),
        new Jumper(30, 8),
        new Jumper(40, 15),
        new Jumper(50, 25),
        new Jumper(60, 10),
    ];
    const ladders = [
        new Jumper(10, 20),
        new Jumper(20, 30),
        new Jumper(30, 40),
        new Jumper(40, 50),
        new Jumper(50, 60),
    ];
    const nextTurnList = [1, 2, 3, 4, 5];
    const gameBoard = new GameBoard(size, snakes, ladders, nextTurnList, dice);
    gameBoard.startGame();
}

main();
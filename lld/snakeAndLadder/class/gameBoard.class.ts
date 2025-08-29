import { Player } from "aws-sdk/clients/gamelift";
import { Jumper } from "./jumper.class";
import { Dice } from "./dice.class";

export class GameBoard {

    private size: number;
    private snakes: Jumper[];
    private ladders: Jumper[];
    private currentPosition: Map<number, number>;
    private nextTurnList: number[]
    private dice: Dice;

    constructor(size: number, snakes: Jumper[], ladders: Jumper[], nextTurnList: number[], dice: Dice) {
        this.size = size;
        this.snakes = snakes;
        this.ladders = ladders;
        this.nextTurnList = nextTurnList;
        this.dice = dice;
        this.currentPosition = new Map<number, number>();
        this.nextTurnList.forEach(playerIndex => {
            this.currentPosition.set(playerIndex, 0);
        });
    }

    public startGame(): void {
        while(this.nextTurnList.length > 0) {
            const playerIndex = this.nextTurnList.length > 0 ? this.nextTurnList.shift() : -1;
            if (playerIndex === undefined) break;
            const currentPosition: number = this.currentPosition.get(playerIndex) || -1;
            let nextPosition: number = currentPosition + this.dice.roll();
            
            if (nextPosition > this.size) {
                this.nextTurnList.push(playerIndex);
                continue;
            }
            else if (nextPosition === this.size) {
                console.log(`Player ${playerIndex} has won the game`);
            } else {
                let isBittenBySnake = false
                this.snakes.forEach(snake => {
                    if (nextPosition === snake.getStart()) {
                        isBittenBySnake = true;
                        nextPosition = snake.getEnd();
                    }
                });
                if (!isBittenBySnake) {
                    this.ladders.forEach(ladder => {
                        if (nextPosition === ladder.getStart()) {
                            nextPosition = ladder.getEnd();
                        }
                    });                    
                }
                this.currentPosition.set(playerIndex, nextPosition);
                if (this.currentPosition.get(playerIndex) === this.size) {
                    console.log(`Player ${playerIndex} has won the game`);
                } else {
                    this.nextTurnList.push(playerIndex);
                }
            }
        }
    }
}
export class Dice {

    private numberOfDice: number;

    constructor(numberOfDice: number) {
        this.numberOfDice = numberOfDice;
    }
    
    public roll(): number {
        return Math.floor(Math.random() * this.numberOfDice) + 1;
    }
}
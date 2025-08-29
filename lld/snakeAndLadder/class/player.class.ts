export class Player {

    private name: string;

    private id: number;

    constructor(name: string, id: number) {
        this.name = name;
        this.id = id;
    }

    public getId(): number {
        return this.id;
    }
}
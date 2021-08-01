abstract public class Mammal extends Animal{
    public Mammal(String name, int age) {
        super(name, age);
    }

    abstract void printBloodType();
}
class Dog extends Mammal{

    public Dog(String name, int age) {
        super(name, age);
    }

    @Override
    public String toString() {

        return (getName()+" is a Dog, aged "+getAge());

    }

    @Override
    public void printBloodType() {
        System.out.printf(", Warm-Blooded!");
    }
}

class FruitBat extends Mammal{

    public FruitBat(String name, int age) {
        super(name, age);
    }

    @Override
    public String toString() {

        return (getName()+" is a FruitBat, aged "+getAge());

    }

    @Override
    public void printBloodType() {
        System.out.printf(", Warm-Blooded!");
    }
}
class Platypus extends Mammal implements Venomous{

    public Platypus(String name, int age) {
        super(name, age);
    }

    @Override
    public String toString() {

        return (getName()+" is a Platypus, aged "+getAge());

    }

    @Override
    public void printBloodType() {
        System.out.printf(", Warm-Blooded!");
    }

    @Override
    public boolean isLethalToAdultHumans() {
        return false;
    }
}
class Human extends Mammal{

    public Human(String name, int age) {
        super(name, age);
    }

    @Override
    public String toString() {

        return (getName()+" is a Human, aged "+getAge());

    }

    @Override
    public void printBloodType() {
        System.out.printf(", Warm-Blooded!");
    }
}

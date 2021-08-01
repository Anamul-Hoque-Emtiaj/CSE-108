public class Animal {
    private String name;
    private int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}
class Bird extends Animal{
    public Bird(String name, int age) {
        super(name, age);
    }
}
class Albatross extends Bird{
    public Albatross(String name, int age) {
        super(name, age);
    }
    @Override
    public String toString() {

        return (getName()+" is a Albatross, aged "+getAge());

    }
}
class Reptile extends Animal{
    public Reptile(String name, int age) {
        super(name, age);
    }
}

class EasternBrownSnake extends Reptile implements Venomous{
    public EasternBrownSnake(String name, int age) {
        super(name, age);
    }

    @Override
    public boolean isLethalToAdultHumans() {
        return true;
    }
    @Override
    public String toString() {

        return (getName()+" is a EasternBrownSnake, aged "+getAge());

    }
}
class Fish extends Animal{
    public Fish(String name, int age) {
        super(name, age);
    }
}
class GreatWhiteShark extends Fish{
    public GreatWhiteShark(String name, int age) {
        super(name, age);
    }
    @Override
    public String toString() {

        return (getName()+" is a GreatWhiteShark, aged "+getAge());

    }
}
class Arachnid extends Animal{
    public Arachnid(String name, int age) {
        super(name, age);
    }
}
class RedBackSpider extends Arachnid implements Venomous{
    public RedBackSpider(String name, int age) {
        super(name, age);
    }

    @Override
    public String toString() {

        return (getName()+" is a RedBackSpider, aged "+getAge());

    }

    @Override
    public boolean isLethalToAdultHumans() {
        return false;
    }
}
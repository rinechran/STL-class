package example;

public class Person {
    private String name;
    private String id;
    public Person(){
        name= "홍길동";
        id = "2013150032";
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }
}

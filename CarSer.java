import java.io.*;

class Vehicle implements Serializable {

    String registrationNumber;

    Vehicle(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }
}

class MarutiCar extends Vehicle {

    String model;

    MarutiCar(String registrationNumber, String model) {
        super(registrationNumber);
        this.model = model;
    }
}

public class CarSer {
    public static void main(String[] args) {
        MarutiCar marutiCar = new MarutiCar("KL01AB1234", "Swift");       
        try {
            FileOutputStream fos = new FileOutputStream("marutiCar.ser");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(marutiCar);
            oos.close();
            fos.close();
            System.out.println("MarutiCar object serialized and saved to marutiCar.ser");
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            FileInputStream fis = new FileInputStream("marutiCar.ser");
            ObjectInputStream ois = new ObjectInputStream(fis);
            MarutiCar deserializedCar = (MarutiCar) ois.readObject();
            ois.close();
            fis.close();

            System.out.println("Deserialized MarutiCar details:");
            System.out.println("Registration Number: " + deserializedCar.registrationNumber);
            System.out.println("Model: " + deserializedCar.model);
        } catch (Exception  e) {
            e.printStackTrace();
        }
    }
}

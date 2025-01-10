import java.util.ArrayList;
import java.util.List;

public class ParkingSimulation {
    public static void main(String[] args) {
        int totalSpots = 4;
        ParkingLot parkingLot = new ParkingLot(totalSpots);
        
        // Read car data from file and parse it
        String filename = "car_schedule.txt";
        List<Car> cars = CarFactory.readCarDataFromFile(filename, parkingLot);
        
        // Start each car as a separate thread
        List<Thread> threads = new ArrayList<>();
        for (Car car : cars) {
            Thread carThread = new Thread(car);
            threads.add(carThread);
            carThread.start();
        }
        
        // Wait for all car threads to finish
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.err.println("Thread interrupted: " + e.getMessage());
            }
        }
        
        // Print final parking lot status
        System.out.println("\nSimulation Complete.");
        System.out.println("Total Cars Served: " + parkingLot.getTotalCarsServed());
        System.out.println("Current Cars in Parking: " + parkingLot.getCurrentCarsInParking());
        System.out.println("Details:");
        System.out.println("Gate 1 served " + CarFactory.getGate1Cars() + " cars.");
        System.out.println("Gate 2 served " + CarFactory.getGate2Cars() + " cars.");
        System.out.println("Gate 3 served " + CarFactory.getGate3Cars() + " cars.");
    }
}
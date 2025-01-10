import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CarFactory {
    private static final List<String> VALID_GATES = List.of("Gate 1", "Gate 2", "Gate 3");
    private static int gate1cars = 0;
    private static int gate2cars = 0;
    private static int gate3cars = 0;

    public static List<Car> readCarDataFromFile(String filename, ParkingLot parkingLot) {
        List<Car> cars = new ArrayList<>();
        
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(", ");
                String gateNum = parts[0].split(" ")[1];
                int carId = Integer.parseInt(parts[1].split(" ")[1]);
                int arrivalTime = Integer.parseInt(parts[2].split(" ")[1]);
                int parkingDuration = Integer.parseInt(parts[3].split(" ")[1]);

                if (!VALID_GATES.contains("Gate " + gateNum)) {
                    System.err.println("Invalid gate: Gate " + gateNum + ". Allowed gates are Gate 1, Gate 2, Gate 3.");
                    continue; // Skip invalid entries
                }

                if(gateNum.equals("1")) gate1cars++;
                else if(gateNum.equals("2")) gate2cars++;
                else if(gateNum.equals("3")) gate3cars++;

                // Create Car object with parsed details and add it to the list
                cars.add(new Car(carId, "Gate " + gateNum, arrivalTime, parkingDuration, parkingLot));
            }

            
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }

        return cars;
    }
    
    public static int getGate1Cars(){
        return gate1cars;
    }

    public static int getGate2Cars(){
        return gate2cars;
    }

    public static int getGate3Cars(){
        return gate3cars;
    }
    

}
public class Car implements Runnable {
    private final int carId;
    private final String gate;
    private final int arrivalTime;
    private final int parkingDuration;
    private final ParkingLot parkingLot;

    // Constructor to initialize Car with parsed file data
    public Car(int carId, String gate, int arrivalTime, int parkingDuration, ParkingLot parkingLot) {
        this.carId = carId;
        this.gate = gate;
        this.arrivalTime = arrivalTime;
        this.parkingDuration = parkingDuration;
        this.parkingLot = parkingLot;
    }

    public int getArrivalTime() {
        return arrivalTime;
    }

    public int getParkingDuration() {
        return parkingDuration;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(arrivalTime * 1000L); // Simulate arrival time

            System.out.println(this + " arrived.");
            parkingLot.acquireParkingSpot(this); // Blocks until a spot is available

            // Simulate the parking duration
            Thread.sleep(parkingDuration * 1000L);
            parkingLot.leaveParking(this);

        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    @Override
    public String toString() {
        return "Car " + carId + " from " + gate;
    }
}
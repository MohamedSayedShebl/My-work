import java.util.concurrent.atomic.AtomicInteger;

public class ParkingLot {
    CustomSemaphore parkingSpots;
    private final AtomicInteger totalCarsServed = new AtomicInteger(0);
    private final AtomicInteger currentCarsInParking = new AtomicInteger(0);

    public ParkingLot(int spots) {
        this.parkingSpots = new CustomSemaphore(spots);
    }

    public void acquireParkingSpot(Car car) throws InterruptedException {
        parkingSpots.acquire(); // Blocks if no spots are available
        synchronized (this) {
            currentCarsInParking.incrementAndGet();
            totalCarsServed.incrementAndGet();
            System.out.println(car + " parked. (Parking Status: " + currentCarsInParking + " spots occupied)");
        }
    }

    public void leaveParking(Car car) {
        synchronized (this) {
            parkingSpots.release();
            currentCarsInParking.decrementAndGet();
            System.out.println(car + " left after " + car.getParkingDuration() + " units of time. (Parking Status: " + currentCarsInParking + " spots occupied)");
        }
    }

    public int getTotalCarsServed() {
        return totalCarsServed.get();
    }

    public int getCurrentCarsInParking() {
        return currentCarsInParking.get();
    }
}
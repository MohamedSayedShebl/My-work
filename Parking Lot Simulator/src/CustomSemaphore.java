public class CustomSemaphore {
    private int permits;
    
    public CustomSemaphore(int permits) {
        if (permits < 0) {
            throw new IllegalArgumentException("Permits cannot be negative");
        }
        this.permits = permits;
    }

     // Acquires a permit, blocking if necessary until one is available.
    public synchronized void acquire() throws InterruptedException {
        while (permits == 0) {
            wait(); // Block until a permit becomes available
        }
        permits--;
    }

    //Releases a permit, potentially unblocking a waiting thread.     
    public synchronized void release() {
        permits++;
        notify(); // Wake up one thread waiting to acquire
    }
    
     //Returns the current number of permits available.
    public synchronized int availablePermits() {
        return permits;
    }
}
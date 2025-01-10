import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import java.io.File;

import static org.junit.Assert.assertTrue;

public class MkdirTest {
    private MkdirCommand mkdir;
    private String testDir;

    @Before
    public void setUp() {
        mkdir = new MkdirCommand();
        testDir = "testDirectory"; // Change this name as needed for testing
    }

    @After
    public void tearDown() {
        File dir = new File(testDir);
        if (dir.exists()) {
            dir.delete(); // Clean up after the test
        }
    }

    @Test
    public void testCreateDirectory() {
        mkdir.execute(testDir);
        File dir = new File(testDir);
        assertTrue("Directory should be created", dir.exists());
    }

    @Test
    public void testDirectoryAlreadyExists() {
        mkdir.execute(testDir); // First creation
        mkdir.execute(testDir); // Attempt to create again
        assertTrue("Directory should still exist", new File(testDir).exists());
    }

    @Test
    public void testEmptyDirectoryName() {
        mkdir.execute("");
        // You can check for console output or use a logging framework to capture it if needed
    }
}

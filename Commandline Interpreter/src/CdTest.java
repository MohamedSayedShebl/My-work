import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.File;
import java.io.IOException;
import java.nio.file.NoSuchFileException;

import static org.junit.jupiter.api.Assertions.*;

class CdTest {
    private Cd cd;
    private File tempDir;
    
    @BeforeEach
    void setUp() throws IOException {
        // Create a temporary directory for testing
        tempDir = new File(System.getProperty("java.io.tmpdir"), "cdTestDir");
        tempDir.mkdir(); // Create the temporary directory
        cd = new Cd();
        cd.cd(tempDir.getAbsolutePath()); // Set the working directory to the tempDir
    }

    @Test
    void testChangeToHomeDirectory() {
        cd.cd();
        assertEquals(new File(System.getProperty("user.home")).getAbsolutePath(), cd.getWorkingDirectory());
    }

    @Test
    void testChangeToParentDirectory() throws IOException {
        // Set a known working directory
        File tempDir = new File(System.getProperty("java.io.tmpdir"), "testDir");
        tempDir.mkdir();
        cd.cd(tempDir.getAbsolutePath());

        // Change to parent directory
        cd.cd("..");
        assertEquals(tempDir.getParent(), cd.getWorkingDirectory());

        // Clean up
        tempDir.delete();
    }

    @Test
    void testChangeToExistingDirectory() throws IOException {
        File tempDir = new File(System.getProperty("java.io.tmpdir"), "testDir");
        tempDir.mkdir();
        
        cd.cd(tempDir.getAbsolutePath());
        assertEquals(tempDir.getAbsolutePath(), cd.getWorkingDirectory());

        // Clean up
        tempDir.delete();
    }

    @Test
    void testChangeToNonExistentDirectory() {
        Exception exception = assertThrows(NoSuchFileException.class, () -> {
            cd.cd("nonExistentDir");
        });

        String expectedMessage = "The directory does not exist: " + new File(tempDir, "nonExistentDir").getAbsolutePath();
        assertEquals(expectedMessage, exception.getMessage());
    }

    @Test
    void testChangeToFileInsteadOfDirectory() throws IOException {
        // Create a temporary file
        File tempFile = new File(System.getProperty("java.io.tmpdir"), "testFile.txt");
        tempFile.createNewFile();

        Exception exception = assertThrows(IOException.class, () -> {
            cd.cd(tempFile.getAbsolutePath());
        });
        assertEquals("Cannot change into a file: " + tempFile.getAbsolutePath(), exception.getMessage());

        // Clean up
        tempFile.delete();
    }
}
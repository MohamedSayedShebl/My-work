import org.junit.Test;
import java.io.File;
import static org.junit.Assert.assertTrue;

public class TouchCommandTest {

    @Test
    public void testExecute() {
        String fileName = "testFile.txt";
        TouchCommand touchCommand = new TouchCommand();

        // Execute the touch command
        touchCommand.execute(new String[]{fileName});

        // Verify that the file is created
        File file = new File(fileName);
        assertTrue("The touch command should create a new file", file.exists());

        // Clean up: Delete the file after test
        file.delete();
    }
}

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;


public class RedirectCommandTest {

    private final String outputFileName = "testOutput.txt";
    private RedirectCommand redirectCommand;

    @Before
    public void setUp() {
        // Initialize the RedirectCommand before each test
        redirectCommand = new RedirectCommand();
    }

    @After
    public void tearDown() {
        // Clean up the output file after each test
        File file = new File(outputFileName);
        if (file.exists()) {
            file.delete();
        }
    }

    @Test
    public void testExecuteRedirectsOutput() {
        // Execute the command and redirect the output to the file
        redirectCommand.execute("pwd", outputFileName);

        // Verify that the file has been created
        File file = new File(outputFileName);
        assertTrue(file.exists(), "Output file should be created");
        // Verify the content of the file
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line = reader.readLine();
            String expectedOutput = new File("").getAbsolutePath(); // Expecting the current directory path for "pwd"
            assertEquals(expectedOutput, line, "The file should contain the redirected output");
        } catch (IOException e) {
            fail("An error occurred while reading the output file");
        }
    }
}


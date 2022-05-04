package Sender;

import static org.junit.Assert.assertNotNull;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class SenderTest {

  private final ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();

  @Before
  public void setUp() {
    System.setOut(new PrintStream(this.outputStreamCaptor));
  }

  @Test
  public void testPrintToConsole() {
    HashMap<String, Float> batteryParams = new HashMap<>();
    batteryParams.put(Sender.TEMPERATURE, 5.48f);
    batteryParams.put(Sender.CR, 0.13f);
    batteryParams.put(Sender.SOC, 65.35f);
    Sender.printToConsole(batteryParams);

    Assert.assertEquals("{Temperature=5.48, Charge Rate=0.13, State of Charge=65.35}",
        this.outputStreamCaptor.toString().trim());
  }

  @Test
  public void testGetRandomValue() {
    assertNotNull(Sender.getRandomValue(0, 10));
  }

  @Test
  public void testGetBatteryParameterValues() {
    ArrayList<HashMap<String, Float>> batteryParam = Sender.getBatteryParameterValues();
    assertNotNull(batteryParam);
    Assert.assertEquals(50, batteryParam.size());
    Assert.assertTrue(batteryParam.get(0).containsKey("Temperature"));
    Assert.assertTrue(batteryParam.get(20).containsKey("Charge Rate"));
    Assert.assertTrue(batteryParam.get(34).containsKey("State of Charge"));
  }
}
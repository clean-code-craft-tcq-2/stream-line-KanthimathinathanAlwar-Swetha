package Sender;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

public class Sender {

  public static String TEMPERATURE = "Temperature";
  public static String SOC = "State of Charge";
  public static String CR = "Charge Rate";
  private static Random randomValue = new Random();
  private static int readingLimit = 50;

  private static float tempUpperLimit = 45;
  private static float tempLowerLimit = 0;
  private static float socUpperLimit = 80;
  private static float socLowerLimit = 20;
  private static float chargeRateLowerLimit = 0.0f;
  private static float chargeRateUpperLimit = 0.8f;


  public static float getRandomValue(final float max, final float min) {
    DecimalFormat decimalFormat = new DecimalFormat("0.00");
    return Float.parseFloat(decimalFormat.format(min + (randomValue.nextFloat() * (max - min))));
  }

  public static ArrayList<HashMap<String, Float>> getBatteryParameterValues() {

    ArrayList<HashMap<String, Float>> dataList = new ArrayList<>();
    int count = readingLimit;
    while (count > 0) {
      HashMap<String, Float> batteryParams = new HashMap<>();
      batteryParams.put(TEMPERATURE, getRandomValue(tempUpperLimit, tempLowerLimit));
      batteryParams.put(SOC, getRandomValue(socUpperLimit, socLowerLimit));
      batteryParams.put(CR, getRandomValue(chargeRateUpperLimit, chargeRateLowerLimit));
      dataList.add(batteryParams);
      printToConsole(batteryParams);
      count--;
    }
    return dataList;
  }

  public static void printToConsole(final HashMap<String, Float> bmsParams) {
    System.out.println(bmsParams);
  }

  public static void main(final String[] args) {
    getBatteryParameterValues();
  }

}


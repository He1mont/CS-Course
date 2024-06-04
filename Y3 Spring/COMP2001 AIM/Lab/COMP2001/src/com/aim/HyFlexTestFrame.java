package com.aim;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Random;

public abstract class HyFlexTestFrame {
	
	protected final long[] SEEDS;
	
	/*
	 * permitted total runs = 15
	 */
	protected final int TOTAL_RUNS = 15;
	
	/*
	 * TODO - you should change this based on your computer's performance!
	 */
	protected final long MILLISECONDS_IN_TEN_MINUTES = 600_000;

	public HyFlexTestFrame() {
		
		/*
		 * Generation of SEED values
		 */
		Random random = new Random(10022017L);
		SEEDS = new long[TOTAL_RUNS];
		
		for(int i = 0; i < TOTAL_RUNS; i++)
		{
			SEEDS[i] = random.nextLong();
		}
		
	}
	
	public int getTotalRuns() {
		
		return this.TOTAL_RUNS;
	}
	
	public long[] getSeeds() {
		
		return this.SEEDS;
	}
	
	public abstract String[] getDomains();
	
	public abstract int[][] getInstanceIDs();
	
	public abstract long getRunTime();
	
	public void saveData(String filePath, String data) {
		
		Path path = Paths.get("./" + filePath);
		if(!Files.exists(path)) {
			try {
				Files.createFile(path);
				
				//add header
				StringBuilder header = new StringBuilder("HH,Run Time,Problem Domain,Instance ID");
				for(int i = 0; i < TOTAL_RUNS; i++) {
					
					header.append(",").append(i);
				}
				
				Files.write(path, (header + "\r\n" + data).getBytes());
				
			} catch (IOException e) {
				System.err.println("Could not create file at " + path.toAbsolutePath());
				System.err.println("Printing data to screen instead...");
				System.out.println(data);
			}
			
		} else {
			
			try {
				byte[] currentData = Files.readAllBytes(path);
				data = "\r\n" + data;
				byte[] newData = data.getBytes();
				byte[] writeData = new byte[currentData.length + newData.length];
				System.arraycopy(currentData, 0, writeData, 0, currentData.length);
				System.arraycopy(newData, 0, writeData, currentData.length, newData.length);
				Files.write(path, writeData);
				
			} catch (IOException e) {
				System.err.println("Could not create file at " + path.toAbsolutePath());
				System.err.println("Printing data to screen instead...");
				System.out.println(data);
			}
			
		}
		
	}
}

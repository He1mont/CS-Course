package com.aim;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Random;
import java.util.stream.IntStream;
import java.util.stream.Stream;

/**
 * 
 * @author Warren G. Jackson
 *
 */
public abstract class TestFrame {
	
	/**
	 * The list of experimental seeds to use for each trial. Generated based on the parent experimental seed.
	 */
	private final long[] SEEDS;
	private final String NEW_LINE = System.lineSeparator();
	private final TestFrameConfig m_oTestConfiguration;
	private final int m_totalRuns;

	/**
	 * 
	 * @param config
	 */
	public TestFrame(TestFrameConfig config) {
		
		this.m_oTestConfiguration = config;
		this.m_totalRuns = config.getTotalRuns();
		
		// use a seeded random number generator to generate "TOTAL_RUNS" seeds
		SEEDS = new long[getTotalRuns()];
		System.arraycopy(config.getSeeds(), 0, SEEDS, 0, Math.min(SEEDS.length, config.getSeeds().length));
		if(config.getSeeds().length < SEEDS.length) {
			
			Random random = new Random(config.getSeeds()[0]);
			for(int i = config.getSeeds().length; i < SEEDS.length; i++) {
				SEEDS[i] = random.nextLong();
			}
		}
	}

	private int getTotalRuns() {
		return m_totalRuns;
	}
	
	/**
	 * @param stream The original stream
	 * @return The <code>stream</code> set to be either parallel or sequential depending on the experimental settings.
	 */
	public Stream<Integer> runUsingExperimentalParallelism(Stream<Integer> stream) {
		
		return ExperimentalSettings.ENABLE_PARALLEL_EXECUTION ? stream.parallel() : stream.sequential();
	}

	/**
	 * @param filePath
	 * @param header
	 * @param data
	 */
	protected void saveData(String filePath, String header, String data) {
		
		Path path = Paths.get("./" + filePath);
		if(!Files.exists(path)) {
			try {
				Files.createFile(path);
				
				//add header
				for(int i = 0; i < getTotalRuns(); i++) {
					
					header += ("," + i);
				}
				
				header += ",Best Solution As String";
				
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
	
	/**
	 * 
	 * @param start
	 * @param end
	 * @return
	 */
	public Stream<Integer> rangeAsStream(int start, int end) {
		
		return IntStream.rangeClosed(start, end).boxed();
	}
	
	/**
	 * 
	 * @param methodName
	 * @param runId
	 * @param bestSolutionValue
	 * @param solution
	 */
	public void logResult(String methodName, int runId, double bestSolutionValue, String solution) {
		
		System.out.println("Heuristic: " + methodName + NEW_LINE +
				"Run ID: " + runId + NEW_LINE +
				"Best Solution Value: " + bestSolutionValue + NEW_LINE +
				"Best Solution: " + solution + NEW_LINE);
	}
	
	public TestFrameConfig getTestConfiguration() {
		
		return m_oTestConfiguration;
	}
	
	public long[] getExperimentalSeeds() {
		
		return SEEDS;
	}
	
	/**
	 * 
	 */
	public abstract void runTests();
	
}

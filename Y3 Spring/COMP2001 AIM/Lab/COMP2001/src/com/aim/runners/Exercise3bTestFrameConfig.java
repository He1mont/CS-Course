package com.aim.runners;

import com.aim.TestFrameConfig;

public class Exercise3bTestFrameConfig extends TestFrameConfig {

	/**
	 * TODO - Change this dependent on your completion of Exercise 3 Task 4.
	 */
	protected final OperatorMode OPERATOR_MODE = OperatorMode.ADVANCED;

	protected final int TOURNAMENT_SIZE = 3;

	/*
	 * permitted total runs = 11
	 */
	protected final int TOTAL_RUNS = 11;

	/*
	 * permitted instance ID's = 1, 7, 9
	 */
	protected final int INSTANCE_ID = 1;

	/*
	 * permitted run times (seconds) = infinite, use generations instead.
	 */
	protected final int RUN_TIME = Integer.MAX_VALUE;

	/*
	 * permitted number of generations = 75
	 */
	protected final int MAX_GENERATIONS = 75;

	/*
	 * permitted population size = 16
	 */
	protected final int POP_SIZE = 16;

	/*
	 * The number of memes in each memeplex
	 */
	protected final int MEMES = 2;

	/*
	 * The number of options that each meme can have.
	 * 
	 * Meme [0] represents intensity of mutation Meme [1] represents choice of hill
	 * climbing operator
	 */
	protected final int[] OPTIONS_PER_MEME = new int[] { 5, 4 };

	/*
	 * permitted innovation rates, 0.0 <= INNOVATION_RATE <= 1.0 
	 */
	protected final double INNOVATION_RATE = 0.0;

	/**
	 * The experimental seed, set as the first date of the in-person lab.
	 */
	private static final long m_parentSeed = 01032024L;

	private static Exercise3bTestFrameConfig oThis;

	private Exercise3bTestFrameConfig() {
		
		super(new long[] { m_parentSeed });
	}

	public synchronized static Exercise3bTestFrameConfig getInstance() {
		
		if (oThis == null) {
			
			oThis = new Exercise3bTestFrameConfig();
		}

		return oThis;
	}

	@Override
	public int getTotalRuns() {
		return this.TOTAL_RUNS;
	}

	@Override
	public int getInstanceId() {
		return this.INSTANCE_ID;
	}

	@Override
	public int getRunTime() {
		return Integer.MAX_VALUE;
	}

	@Override
	public String getMethodName() {
		return "Multimeme Memetic Algorithm";
	}

	public int getPopulationSize() {
		return this.POP_SIZE;
	}

	public int getMemeCount() {
		return this.MEMES;
	}

	public int[] getOptionsPerMeme() {
		return this.OPTIONS_PER_MEME;
	}

	@Override
	public String getConfigurationAsString() {
		return "Population size = " + getPopulationSize();
	}

	public String getBoxPlotTitle() {

		String config = getConfigurationAsString();
		return "Results for " + getMethodName() + " given " + MAX_GENERATIONS + " generations for solving instance ID "
				+ getInstanceId() + " over " + getTotalRuns() + " runs"
				+ (config == null ? "." : (" with " + config + "."));
	}

	public enum OperatorMode {

		BASIC, ADVANCED, CUSTOM;
	}
}

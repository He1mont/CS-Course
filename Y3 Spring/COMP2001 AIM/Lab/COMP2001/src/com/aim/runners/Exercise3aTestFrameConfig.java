package com.aim.runners;

import com.aim.TestFrameConfig;

import java.lang.reflect.GenericArrayType;

/**
 * Test frame/experimental configuration for exercise 3a.
 * 
 * @author Warren G. Jackson
 * @since 26/02/2024
 * @version 1.0.0
 *
 */
public class Exercise3aTestFrameConfig extends TestFrameConfig {

	/*
	 * permitted values = { Mode.GA, Mode.MA } Mode.GA = genetic algorithm ( local
	 * search <- NOOP ) Mode.MA = memetic algorithm ( local search <- DBHC_IE )
	 * 
	 * You are encouraged to play around with this setting in your own time :)
	 */
	protected final Mode MODE = Mode.GA;

	/**
	 * Permitted values for task 2: { Selection.RANDOM }
	 * Permitted values for task 3: { Selection.TOURNAMENT }
	 *
	 */
	protected final Selection P1_SELECTION = Selection.TOURNAMENT;

	/**
	 * Permitted values for task 2: { Selection.FITTEST }
	 * Permitted values for task 3: { Selection.TOURNAMENT }
	 *
	 */
	protected final Selection P2_SELECTION = Selection.FITTEST;

	/**
	 * Permitted values for task 2: { Replacement.BASIC }
	 * Permitted values for task 3: { Replacement.TRANS_GENERATIONAL }
	 */
	protected final Replacement REPLACEMENT = Replacement.TRANS_GENERATIONAL;

	/*
	 * permitted total runs = 11
	 */
	protected final int TOTAL_RUNS = 11;

	/*
	 * permitted instance ID's = 1
	 */
	protected final int INSTANCE_ID = 1;

	/*
	 * permitted population sizes = 4, 8, 16
	 */
	public final int POP_SIZE = 16;

	public final int TOURNAMENT_SIZE = 3;

	private static final long m_parentSeed = 01032024L;
	
	/**
	 * 
	 */
	private static Exercise3aTestFrameConfig oThis;

	/**
	 * 
	 */
	private Exercise3aTestFrameConfig() {

		super(new long[] {m_parentSeed});
	}

	/**
	 * 
	 * @return
	 */
	public synchronized static Exercise3aTestFrameConfig getInstance() {

		if (oThis == null) {
			oThis = new Exercise3aTestFrameConfig();
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
		return "Memetic Algorithm";
	}

	public int getPopulationSize() {
		return this.POP_SIZE;
	}

	@Override
	public String getConfigurationAsString() {
		return getMethodName() + " ( " + MODE.toString() + "_Mode ) given " + MODE.getGenerations() 
		+ " generations for solving instance ID " + getInstanceId()  + " over " + getTotalRuns() + " runs"
		+ (" with Population size = " + getPopulationSize() + ".");
	}

	/**
	 * Execution mode for the Memetic Algorithm.
	 * 
	 * @author Warren G. Jackson
	 * @since 31/01/2021
	 * @version 1.0.0
	 *
	 */
	public enum Mode {

		GA(2500), MA(100);

		private final int generations;

		Mode(int generations) {
			this.generations = generations;
		}

		public int getGenerations() {
			return generations;
		}
	}

	public enum Selection {

		TOURNAMENT, RANDOM, FITTEST;
	}

	public enum Replacement {

		BASIC, TRANS_GENERATIONAL;
	}
}

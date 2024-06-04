package com.aim.runners;

import com.aim.TestFrameConfig;
import com.aim.metaheuristics.singlepoint.simulatedannealing.CoolingSchedule;
import com.aim.metaheuristics.singlepoint.simulatedannealing.GeometricCooling;
import com.aim.metaheuristics.singlepoint.simulatedannealing.LundyAndMees;

/**
 * Test frame/experimental configuration for lab 3.
 * 
 * @author Warren G. Jackson
 * @since 31/01/2021
 * @version 1.0.0
 *
 */
public class Exercise2bTestFrameConfig extends TestFrameConfig {

	public enum Schedule {
		GEOMETRIC, LUNDY_AND_MEES;
	}

	/*
	 * permitted schedules = Schedule.GEOMETRIC, Schedule.LUNDY_AND_MEES Change this
	 * to use the respective cooling schedule during experiments.
	 */
	protected final Schedule schedule = Schedule.LUNDY_AND_MEES;

	/**
	 * The experimental seed, set as the date the ILS lab was released.
	 */
	private static final long m_parentSeed = 16022024L;

	/*
	 * permitted total runs = 11
	 */
	protected final int TRIALS_PER_TEST = 11;

	/*
	 * permitted instance ID's = 1
	 */
	protected final int INSTANCE_ID = 1;

	/*
	 * permitted run times (seconds) = 10
	 */
	protected final int RUN_TIME = 10;

	/**
	 * 
	 */
	private static Exercise2bTestFrameConfig oThis;

	/**
	 * 
	 */
	private Exercise2bTestFrameConfig() {

		super(new long[] {m_parentSeed});
	}

	/**
	 * 
	 * @return
	 */
	public synchronized static Exercise2bTestFrameConfig getInstance() {

		if (oThis == null) {
			oThis = new Exercise2bTestFrameConfig();
		}

		return oThis;
	}

	@Override
	public int getTotalRuns() {
		return this.TRIALS_PER_TEST;
	}

	@Override
	public int getInstanceId() {
		return this.INSTANCE_ID;
	}

	@Override
	public int getRunTime() {
		return this.RUN_TIME;
	}

	@Override
	public String getMethodName() {
		return "Simulated Annealing";
	}

	@Override
	public String getConfigurationAsString() {
		return "using " + schedule.name() + " cooling";
	}

	public CoolingSchedule getCoolingSchedule(double initialSolutionFitness) {

		switch (schedule) {
		case GEOMETRIC:
			return new GeometricCooling(initialSolutionFitness);
		case LUNDY_AND_MEES:
			return new LundyAndMees(initialSolutionFitness);
		default:
			return null;
		}

	}
}

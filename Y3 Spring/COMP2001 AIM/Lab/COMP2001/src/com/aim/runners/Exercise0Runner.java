package com.aim.runners;

import java.util.Random;
import java.util.stream.IntStream;

import com.aim.TestFrame;
import com.aim.TestFrameConfig;

import com.aim.pseudorandom.RandomWalk;
import com.aim.pseudorandom.Result;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

/**
 * Class for running the experiment(s) in Lab 0.
 *
 * @author Warren G. Jackson
 */
public class Exercise0Runner extends TestFrame {

	/**
	 * 
	 */
	public Exercise0Runner() {

		super(Exercise0TestFrameConfig.getConfig());
	}

	/**
	 * 
	 * @param seed
	 * @param instance
	 * @param timeLimit
	 * @return
	 */
	public Result runTest(int trialId, long seed, int instance, int timeLimit) {

		Random random = new Random(seed);
		SAT sat = new SAT(instance, timeLimit, random);
		RandomWalk rw = new RandomWalk(sat, random);
		rw.run();
		
		return new Result(sat.toString(), instance, trialId, seed, sat.getBestSolutionValue(), rw.getTimeTaken(), timeLimit);
	}

	/**
	 * 
	 * @param result
	 */
	private void printResult(Result result) {

		System.out.println(String.format("%d,%.1f,%.3f,%.3f", result.seed(), result.f_best(), result.cpuTimeTaken(), result.nominalTimeTaken()));
	}

	@Override
	public void runTests() {

		TestFrameConfig oTestConfiguration = getTestConfiguration();

		final int instance = oTestConfiguration.getInstanceId();
		final int timeLimit = oTestConfiguration.getRunTime();
		final int totalRuns = oTestConfiguration.getTotalRuns();
		final long[] seeds = getExperimentalSeeds();

		System.out.println(getTestConfiguration().getConfigurationAsString());
		System.out.println("seed,f_best,time_taken(CPU seconds),time_taken(nominal seconds)");

		runUsingExperimentalParallelism(IntStream.range(0, totalRuns).boxed())
				.map(i -> runTest(i, seeds[i], instance, timeLimit)).forEachOrdered(this::printResult);
	}

	/**
	 * 
	 * @param args The program arguments, not used.
	 */
	public static void main(String[] args) {

		Exercise0Runner runner = new Exercise0Runner();
		runner.runTests();
	}
}

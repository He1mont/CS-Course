package com.aim.metaheuristics.singlepoint.simulatedannealing;

/**
 * 
 * @author Warren G. Jackson
 *
 */
public class LundyAndMees implements CoolingSchedule {
	
	/**
	 * Maintain the state of the current temperature
	 */
	private double dCurrentTemperature;
	
	/**
	 * The $\beta$ parameter of the Lundy and Mees cooling schedule.
	 * Recall from the lectures what a "reasonable" setting should be but be prepared to experiment to find a "good" value!
	 */
	private final double dBeta;
	
	/**
	 * 
	 * @param initialSolutionFitness
	 *            The objective value of the initial solution. Maybe useful (or
	 *            not) for some setting?
	 */
	public LundyAndMees(double initialSolutionFitness) {
		double c = 1.0d;
		this.dCurrentTemperature = c * initialSolutionFitness;
		this.dBeta = 0.0001d;
	}
	
	@Override
	public double getCurrentTemperature() {
		return dCurrentTemperature;
	}

	/**
	 * DEFINITION: T_{i + 1} = T_i / ( 1 + beta * T_i )
	 */
	@Override
	public void advanceTemperature() {
		dCurrentTemperature /= (1 + dBeta * dCurrentTemperature);
	}
	
	@Override
	public String toString() {
		
		return "Lundy and Mees";
	}

}

package com.aim.metaheuristics.population.multimeme;

import java.util.Random;

import com.aim.metaheuristics.population.MemeplexInheritanceMethod;
import com.aim.metaheuristics.population.ParentSelection;
import com.aim.metaheuristics.population.heuristics.*;

import com.aim.metaheuristics.population.memetic.FittestSelection;
import com.aim.metaheuristics.population.memetic.RandomSelection;
import com.aim.metaheuristics.population.memetic.TransGenerationalReplacementWithElitistReplacement;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.Meme;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.CrossoverHeuristic;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationHeuristic;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationReplacement;
import uk.ac.nott.cs.aim.searchmethods.PopulationBasedSearchMethod;

public class MultiMeme extends PopulationBasedSearchMethod {

	/**
	 * The innovation rate setting
	 */
	private final double innovationRate;
	
	private final CrossoverHeuristic crossover;
	private final BitMutation mutation;
	private final PopulationReplacement replacement;
	private final ParentSelection p1selection;
	private final ParentSelection p2selection;

	private final MemeplexInheritanceMethod inheritance;
	
	/**
	 * The possible local search operators to use.
	 */
	private final PopulationHeuristic[] lss; 
	
	// Constructor used for testing. Please do not remove!
	/**
	 *
	 * @param problem
	 * @param rng
	 * @param populationSize
	 * @param innovationRate
	 * @param crossover
	 * @param mutation
	 * @param replacement
	 * @param p1selection
	 * @param p2selection
	 * @param inheritance
	 * @param lss
	 */
	public MultiMeme(SAT problem, Random rng, int populationSize, double innovationRate, CrossoverHeuristic crossover,
							 BitMutation mutation, PopulationReplacement replacement, ParentSelection p1selection, ParentSelection p2selection, MemeplexInheritanceMethod inheritance,
							 PopulationHeuristic[] lss) {

		super(problem, rng, populationSize);

		this.innovationRate = innovationRate;
		this.crossover = crossover;
		this.mutation = mutation;
		this.replacement = replacement;
		this.p1selection = p1selection;
		this.p2selection = p2selection;
		this.inheritance = inheritance;
		this.lss = lss;
	}

	/**
	 * Constructor called when using the CUSTOM operator mode.
	 * You need to create each of the components by yourself!
	 * @param problem
	 * @param rng
	 * @param populationSize
	 * @param innovationRate
	 */
	public MultiMeme(SAT problem, Random rng, int populationSize, double innovationRate) {

		super(problem, rng, populationSize);

		this.innovationRate = innovationRate;
		this.crossover = new PTX1(problem, rng);
		this.mutation = new BitMutation(problem, rng);
		this.replacement = new TransGenerationalReplacementWithElitistReplacement();
		this.p1selection = new RandomSelection(problem, rng, populationSize);
		this.p2selection = new FittestSelection(problem, rng, populationSize);
		this.inheritance = new SimpleInheritanceMethod(problem, rng);
		this.lss = new PopulationHeuristic[] { // create mapping for local search operators used for meme in meme index 1
				new DBHC_OI(problem, rng), // [0]
				new DBHC_IE(problem, rng), // [1]
				new SDHC_OI(problem, rng), // [2]
				new SDHC_IE(problem, rng)  // [3]
		};
	}

	public void runMainLoop() {
		for (int i = 0; i < POPULATION_SIZE; i += 2) {
			// Mate Selection
			int p1 = p1selection.parentSelection();
			int p2 = p2selection.parentSelection();
			if (p1 == p2) {
				p2 = (p2 + 1) % POPULATION_SIZE;
			}
			// Cross over
			int c1 = i + POPULATION_SIZE;
			int c2 = i + POPULATION_SIZE + 1;
			crossover.applyHeuristic(p1, p2, c1, c2);
			// Inheritance
			inheritance.performMemeticInheritance(p1, p2, c1, c2);
			// Mutation to memes
			performMutationOfMemeplex(c1);
			performMutationOfMemeplex(c2);
			// Mutation to offsprings
			applyMutationForChildDependentOnMeme(c1, 0);
			applyMutationForChildDependentOnMeme(c2, 0);
			// Local search to offsprings
			applyLocalSearchForChildDependentOnMeme(c1, 1);
			applyLocalSearchForChildDependentOnMeme(c2, 1);
		}
		// Replacement
		replacement.doReplacement(problem, POPULATION_SIZE);
	}
	
	/**
	 * Applies mutation to the child dependent on its current meme option for mutation.
	 * Mapping of meme option to IOM: IntensityOfMutation <- memeOption;
	 * 
	 * @param childIndex The solution memory index of the child to mutate.
	 * @param memeIndex The meme index used for storing the meme relating to the intensity of mutation setting.
	 */
	public void applyMutationForChildDependentOnMeme(int childIndex, int memeIndex) {

		int iom = problem.getMeme(childIndex, memeIndex).getMemeOption();
		mutation.setMutationRate(iom);
		mutation.applyHeuristic(childIndex);
	}
	
	/**
	 * Applies the local search operator to the child as specified by its current meme option.
	 * 
	 * @param childIndex The solution memory index of the child to mutate.
	 * @param memeIndex The meme index used for storing the meme relating to the local search operator setting.
	 */
	public void applyLocalSearchForChildDependentOnMeme(int childIndex, int memeIndex) {

		int index = problem.getMeme(childIndex, memeIndex).getMemeOption();
		lss[index].applyHeuristic(childIndex);
	}
	
	/**
	 * Applies mutation to each meme within the memeplex of the specified solution with probability
	 * dependent on the innovation rate.
	 * 
	 * HINT: mutation does not mean bit flip; it only means in this case 
	 * 		that you should MODIFY the current value of the meme option
	 * 		subject to the above definition.
	 * 
	 * @param solutionIndex The solution memory index of the solution to mutate the memeplex of.
	 */
	public void performMutationOfMemeplex(int solutionIndex) {

		if (rng.nextDouble() >= innovationRate) {
			return;
		}
		problem.getMeme(solutionIndex, 0).setMemeOption(rng.nextInt(5));
		problem.getMeme(solutionIndex, 1).setMemeOption(rng.nextInt(4));
	}
	
	public String toString() {
		
		return "Multimeme Memetic Algorithm";
	}
	
}

package com.aim.hyperheuristics;



import com.aim.HyFlexUtilities;

import AbstractClasses.HyperHeuristic;
import AbstractClasses.ProblemDomain;
import AbstractClasses.ProblemDomain.HeuristicType;

public class RLILS_AM_HH extends HyperHeuristic {
	
	private final int m_iDefaultScore, m_iLowerBound, m_iUpperBound;
	
	/**
	 * 
	 * @param seed The experimental seed.
	 * @param defaultScore The default score to give each heuristic in RWS.
	 * @param lowerBound The lower bound for each heuristic's score in RWS.
	 * @param upperBound The upper bound for each heursitic's score in RWS.
	 */
	public RLILS_AM_HH(long seed, int defaultScore, int lowerBound, int upperBound) {
		
		super(seed);
		
		this.m_iDefaultScore = defaultScore;
		this.m_iLowerBound = lowerBound;
		this.m_iUpperBound = upperBound;
	}

	/**
	 * TODO - Implement a selection hyper-heuristic using a reinforcement learning based
	 * roulette wheel selection (RWS) heuristic selection method accepting all moves (AM).
	 * 
	 * PSEUDOCODE:
	 * 
	 * INPUT: problem_instance, default_score, lower_bound, upper_bound
	 * mtns <- { MUTATION } 
	 * lss <- { LOCAL_SEARCH } 
	 * hs <- { (a, b) | a <- mtns, b <- lss }
	 * s <- initialiseSolution();
	 * rws <- initialiseNewRouletteWheelSelectionMethod();
	 * 
	 * WHILE termination criterion is not met DO
	 *     h <- rws.performRouletteWheelSelection();
	 *     s' <- h(s);
	 *     updateHeuristicScore(h_i, f(s), f(s'));
	 *     accept(); // all moves
	 * END_WHILE
	 * 
	 * return s_{best};
	 */
	
	// remember to update the roulette wheel selection based on feedback
	public void solve(ProblemDomain oProblem) {

		// mtns <- { MUTATION }, lss <- { LOCAL_SEARCH }
		int[] mtn = oProblem.getHeuristicsOfType(HeuristicType.MUTATION);
		int[] lss = oProblem.getHeuristicsOfType(HeuristicType.LOCAL_SEARCH);

		// hs <- { (a, b) | a <- mtns, b <- lss }
		HeuristicPair[] heuristicPairs = new HeuristicPair[mtn.length * lss.length];
		int index = 0;
		for (int mutation : mtn) {
			for (int localSearch : lss) {
				heuristicPairs[index++] = new HeuristicPair(mutation, localSearch);
			}
		}
		// s <- initialiseSolution();
		int CURRENT_SOLUTION_INDEX = 0, CANDIDATE_SOLUTION_INDEX = 1;
		oProblem.initialiseSolution(CURRENT_SOLUTION_INDEX);

		// rws <- initialiseNewRouletteWheelSelectionMethod();
		RouletteWheelSelection rws = new RouletteWheelSelection(heuristicPairs, m_iDefaultScore, m_iLowerBound, m_iUpperBound, rng);

		// WHILE termination criterion is not met DO
		while (!hasTimeExpired()) {
			// h <- rws.performRouletteWheelSelection();
			HeuristicPair hp = rws.performRouletteWheelSelection();

			// s' <- h(s);
			oProblem.applyHeuristic(hp.h1(), CURRENT_SOLUTION_INDEX, CANDIDATE_SOLUTION_INDEX);
			oProblem.applyHeuristic(hp.h2(), CANDIDATE_SOLUTION_INDEX, CANDIDATE_SOLUTION_INDEX);

			// updateHeuristicScore(h_i, f(s), f(s'));
			if (oProblem.getFunctionValue(CANDIDATE_SOLUTION_INDEX) < oProblem.getFunctionValue(CURRENT_SOLUTION_INDEX)) {
				rws.incrementScore(hp);
			} else {
				rws.decrementScore(hp);
			}

			oProblem.copySolution(CANDIDATE_SOLUTION_INDEX, CURRENT_SOLUTION_INDEX);
		}
	}
	
	public String toString() {

		return "RL-ILS_AM_HH";
	}

}

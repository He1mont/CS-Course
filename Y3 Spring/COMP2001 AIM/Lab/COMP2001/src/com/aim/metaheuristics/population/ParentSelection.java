package com.aim.metaheuristics.population;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

import java.util.Random;

/**
 * Abstracting parent selection methods.
 *
 * @author Warren G Jackson
 * @since 22-02-2024
 */
public abstract class ParentSelection {

    protected final Random rng;
    protected final int POPULATION_SIZE;
    protected final SAT problem;

    public ParentSelection(SAT problem, Random rng, int POPULATION_SIZE) {

        this.problem = problem;
        this.rng = rng;
        this.POPULATION_SIZE = POPULATION_SIZE;
    }

    /**
     *
     * @return The index of a parent solution.
     */
    public abstract int parentSelection();
}

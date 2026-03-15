#pragma once
#include <fftw3.h>
#include "Arrow.h"
#include <complex>
class Simulation
{
public:
	Simulation(std::vector<double>x, std::vector<double>y, int numArrows, double t, int updRate);
	fftw_complex* fft(int N, std::vector<std::complex<double>> points);
	void initSimulation();
	void runSimulation(double time);
private:
	void drawSimulation(double time);
	void updPositions(double time);
	std::vector<std::complex<double>> m_points;
	std::vector<Arrow> m_arrows;
	int m_numArrows;
	double m_t;
	double m_lastUpdTime;
	int m_updRate;
};
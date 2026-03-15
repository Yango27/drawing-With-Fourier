#include "simulation.h"

Simulation::Simulation(std::vector<double>x, std::vector<double>y, int numArrows, double t, int updRate)
{
	for (int i = 0; i < x.size(); i++)
	{
		m_points.push_back(std::complex<double>(x[i], y[i]));
	}
	m_numArrows = numArrows;
	m_t = t;
	m_updRate = updRate;
	m_lastUpdTime = 0;
}

fftw_complex* Simulation::fft(int N, std::vector<std::complex<double>> points)
{
	fftw_complex* in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);
	fftw_complex* out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);

	for (int i = 0; i < N; i++) {
		in[i][0] = points[i].real(); 
		in[i][1] = points[i].imag(); 
	}

	fftw_plan p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(p);
	return out;
}

void Simulation::initSimulation()
{
	fftw_complex* out = fft(m_points.size(), m_points);
	double sum = 0;
	for (int i = 0; i < m_numArrows; i++)
	{
		double radius = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
		double phase = atan2(out[i][1], out[i][0]);
		double angularV = 2 * M_PI * i;
		m_arrows.push_back(Arrow(0, 0, radius, angularV, phase));
		sum += radius;
	}
	for (int i = 1; i < m_arrows.size(); i++)
		m_arrows[i].setRadius(m_arrows[i].getRadius() / sum);
}

void Simulation::updPositions(double time)
{
	if (time - m_lastUpdTime >= 1.0f / m_updRate)
	{
		for (int i = 0; i < m_arrows.size(); i++)
			m_arrows[i].phasorSpinning(m_t);

		m_lastUpdTime = time;
	}
}

void Simulation::drawSimulation(double time)
{
	m_arrows[0].drawArrow();
	m_arrows[0].drawCircle();
	for (int i = 1; i < m_arrows.size() - 1; i++)
	{
		m_arrows[i].setCx(m_arrows[i - 1].getX());
		m_arrows[i].setCy(m_arrows[i - 1].getY());
		m_arrows[i].drawArrow();
		m_arrows[i].drawCircle();
	}
	m_arrows[m_arrows.size() - 1].setCx(m_arrows[m_arrows.size() - 2].getX());
	m_arrows[m_arrows.size() - 1].setCy(m_arrows[m_arrows.size() - 2].getY());
	m_arrows[m_arrows.size() - 1].drawArrow();
	m_arrows[m_arrows.size() - 1].drawCircle();
	m_arrows[m_arrows.size() - 1].drawPath();
}

void Simulation::runSimulation(double time)
{
	updPositions(time);
	drawSimulation(time);
}


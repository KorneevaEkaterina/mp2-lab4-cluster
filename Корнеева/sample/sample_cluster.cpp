#include <iostream>
#include <ctime>
#include "cluster.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		size_t N;
		float alpha;
		int k, T, t;

		std::cout << "������� ���������� ����� (�� 16 �� 64): ";
		std::cin >> N;

		std::cout << "������� ����������� ��������� ������� (0 < alpha < 1): ";
		std::cin >> alpha;

		std::cout << "������� ������������ ���������� �������, ���������� �� ����: ";
		std::cin >> k;

		std::cout << "������� ������������ ����� ���������� ������ ������� (� ������): ";
		std::cin >> t;

		std::cout << "������� ����� ������ (� ������): ";
		std::cin >> T;

		TCluster cluster(N);

		while (T > 0)
		{
			cluster.generate_tasks(alpha, k, t);
			cluster.process();
			--T;
		}

		auto stats = cluster.get_statistics();

		std::cout << "\n���������� ������ ��������:\n";
		std::cout << "����� ���������� ������ ������: " << stats.time_of_working << "\n";
		std::cout << "���������� ����������� �����: " << stats.count_of_completed << "\n";
		std::cout << "���������� ������������� �����: " << stats.count_of_incompleted << "\n";
		std::cout << "�������� ��������: " << stats.cluster_load << "%\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "������: " << e.what() << std::endl;
	}

	return 0;
}
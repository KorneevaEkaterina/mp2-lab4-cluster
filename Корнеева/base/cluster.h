#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"
#include <vector>
#include <random>

using namespace std;


class TCluster
{
public:
	struct Task
	{
		int tacts;                     // ����� ���������� ������ � ������
		int required_nodes;            // ���������� �����, ����������� ��� ���������� ������
		enum Status
		{
			Waiting,
			Processing,
			Completed
		} status;                      // ������ ������
	};

	struct Statistics
	{
		size_t time_of_working;         // ����� ���������� ������ ������
		size_t count_of_completed;      // ���������� ����������� �����
		size_t count_of_incompleted;    // ���������� ������������� �����
		float cluster_load;             // �������� �������� � ���������
	};

private:
	size_t nodes;                        // ����� ���������� ����� � ��������
	size_t nodes_free;                   // ���������� ��������� �����
	size_t total_tasks;                  // ����� ���������� ��������� �����
	size_t completed_tasks;              // ���������� ����������� �����
	vector<Task> tasks;                  // ������ ���� ��������� �����
	TQueue<Task> waiting_queue;          // ������� �������� �����
	TQueue<Task> processing_queue;       // ������� ����� �� ����������

	float total_load;                    // ���������� ��� ���������� ����� �������� �� ����� �����
	size_t T;                            // ���������� ������

public:
	// �����������, ������������� ����� ���������� �����
	explicit TCluster(size_t nodes); 

	// ��������� ����� �������� �������� ����������
	void generate_tasks(float alpha, int k, int max_tacts); 

	// ��������� ����� � ������� �������� � �� ����������
	void process();

	// ��������� ���������� � ������ ��������
	Statistics get_statistics() const;

	const vector<Task>& get_waiting_tasks() const { return tasks; }                // ��������� ������ ����� � ��������
	const TQueue<Task>& get_processing_queue() const { return processing_queue; }  // ��������� ������� ����� �� ����������
	const TQueue<Task>& get_waiting_queue() const { return waiting_queue; }        // ��������� ������� ����� � ��������

	float get_cluster_load() const;                                // ���������� �������� �������� ��������
	size_t get_total_tasks() const { return total_tasks; }         // ��������� ������ ���������� ��������� �����
	size_t get_completed_tasks() const { return completed_tasks; } // ��������� ���������� ����������� �����
};

#endif // __CLUSTER_H__
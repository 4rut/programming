import json

with open('in.json', 'r') as file:
    data = json.load(file)

count_users = 0
for item in data:
    if item["userId"] > count_users:
        count_users = item["userId"]

complited_task = []
for i in range(count_users):
    complited_task.append(0)

for item in data:
    for j in range(count_users):
        if item["userId"] == j and item["completed"]:
            complited_task[j] += 1

new_data = []
for i in range(count_users):
    new_data.append("")


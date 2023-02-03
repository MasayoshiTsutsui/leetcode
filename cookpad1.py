import json
import requests
import sys

def main():
    args = sys.argv
    api_url = args[1]
    date = args[2]

    advs_text = requests.get(api_url).text
    advs_json = json.loads(advs_text)
    with open('delivery_plans.csv', 'w') as f:
        f.write("delivery_plan_id,client,target_date,goal_impressions,budget\n")
        for adv_client in advs_json:
            for plan in adv_client["delivery_plans"]:
                if plan["target_date"] == date:
                    pid = str(plan["delivery_plan_id"])
                    company = adv_client["client"]
                    goal = str(plan["goal_impressions"])
                    budget = str(plan["budget"])
                    f.write(','.join([pid, company, date, goal, budget]))
                    f.write('\n')
    f.close()
main()
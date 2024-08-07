import requests

url = 'http://127.0.0.1:5000/get_recipes'
data = {"ingredients": ["chicken", "tomato", "cheese"]}

response = requests.post(url, json=data)
print(response.json())

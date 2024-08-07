from flask import Flask, request, jsonify

app = Flask(__name__)

# Simple in-memory recipe database
recipes_db = [
    {"name": "Chicken Parmesan", "ingredients": ["chicken", "tomato", "cheese"]},
    {"name": "Tomato Soup", "ingredients": ["tomato", "cheese"]},
    {"name": "Cheese Sandwich", "ingredients": ["cheese"]}
]

@app.route('/get_recipes', methods=['POST'])
def get_recipes():
    data = request.json
    ingredients = data.get('ingredients', [])
    matching_recipes = find_matching_recipes(ingredients)
    return jsonify({'recipes': matching_recipes})

def find_matching_recipes(ingredients):
    matching_recipes = []
    for recipe in recipes_db:
        if all(ingredient in recipe['ingredients'] for ingredient in ingredients):
            matching_recipes.append(recipe['name'])
    return matching_recipes

if __name__ == '__main__':
    app.run(debug=True)

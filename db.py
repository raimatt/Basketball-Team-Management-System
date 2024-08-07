from sqlalchemy import create_engine, and_
from sqlalchemy.orm import sessionmaker

engine = create_engine('sqlite:///recipes.db')
Session = sessionmaker(bind=engine)
session = Session()

def find_matching_recipes(ingredients):
    # Replace with actual query logic
    query = session.query(Recipe).filter(
        and_(*[Recipe.ingredients.contains(ingredient) for ingredient in ingredients])
    )
    return [recipe.name for recipe in query.all()]

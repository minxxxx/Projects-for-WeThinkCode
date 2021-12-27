from django.db import models
from django.contrib.auth.models import User

# Create your models here.
class Article(models.Model):
	title = models.CharField(max_length = 64, null = False)
	author = models.ForeignKey(User, null = False)
	created = models.DateTimeField(auto_now_add=True, null = False) # la date sera inserre automatiquement
	synopsis = models.CharField(max_length = 312, null = False)
	content = models.TextField(null = False)
	def __str__(self):
		return self.title

class UserFavoriteArticle(models.Model):
	user = models.ForeignKey(User, null = False)
	article = models.ForeignKey(Article, null = False)
	def __str__(self):
		return self.article.title
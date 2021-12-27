from django.contrib import admin
from .models import Article, UserFavoriteArticle

# Register your models here.
class ArticleAdmin(admin.ModelAdmin):
	model = Article

class UserFavoriteArticleAdmin(admin.ModelAdmin):
	model = UserFavoriteArticle

admin.site.register(Article, ArticleAdmin)
admin.site.register(UserFavoriteArticle, UserFavoriteArticleAdmin)
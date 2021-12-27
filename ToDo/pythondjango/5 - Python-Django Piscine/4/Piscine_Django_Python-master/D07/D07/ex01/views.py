from django.shortcuts import render
from django.views.generic import ListView
from django.core.urlresolvers import reverse
from django.shortcuts import redirect
from django.views.generic.base import RedirectView
from django.views.generic.detail import DetailView
from ex00.models import Article, UserFavoriteArticle

# Create your views here.
class PublicationsView(ListView):
	model = Article
	

class ArticleDetailView(DetailView):
	model = Article
	
	
class FavoritesView(ListView):
	model = UserFavoriteArticle
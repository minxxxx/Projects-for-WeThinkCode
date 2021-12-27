from django.shortcuts import render
from django.views.generic import ListView
from django.core.urlresolvers import reverse
from django.shortcuts import redirect
from django.views.generic.base import RedirectView
from .models import Article

# Create your views here.
class ArticlesView(ListView):
	model = Article


# https://docs.djangoproject.com/fr/1.11/ref/class-based-views/base/#redirectview
class HomeRedirectView(RedirectView):
    """
    simple redirection vers articles
    """
    permanent = False
    query_string = True
    pattern_name = 'articles'
    #pattern_name = redirect(reverse('articles'))

    def get_redirect_url(self, *args, **kwargs):

        return super(HomeRedirectView, self).get_redirect_url(*args, **kwargs)



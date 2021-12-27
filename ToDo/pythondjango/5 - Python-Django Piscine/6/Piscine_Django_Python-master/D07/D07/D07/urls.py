"""D07 URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.11/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.conf.urls import url, include
    2. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import url, include
from django.contrib import admin
from django.contrib.auth import views as auth_views
from ex00.views import HomeRedirectView, ArticlesView
from ex01.views import PublicationsView, ArticleDetailView, FavoritesView
from ex02.views import RegisterView

urlpatterns = [
    url(r'^admin/', admin.site.urls),
    # ex00
	url(r'^$', HomeRedirectView.as_view(), name='home'),
	url(r'^articles/$', ArticlesView.as_view(template_name = 'ex00/articles.html'), name="articles"),
	url(r'^login/$', auth_views.LoginView.as_view(template_name='ex00/login.html'), name='login'),
	#ex01
	url(r'^publications/$', PublicationsView.as_view(template_name = 'ex01/publications.html'), name='publications'),
	url(r'^detail/(?P<pk>[0-9]+)/$', ArticleDetailView.as_view(template_name = "ex01/detail.html"), name="detail"),
	url(r'^logout/$', auth_views.LogoutView.as_view(template_name='ex01/logout.html'), name='logout'),
	url(r'^favorites/$', FavoritesView.as_view(template_name='ex01/favorites.html'), name="favorites"),
	#ex02
	# url(r'^register/$', RegisterView.as_view(template_name='ex02/register.html'), name="register"),

]

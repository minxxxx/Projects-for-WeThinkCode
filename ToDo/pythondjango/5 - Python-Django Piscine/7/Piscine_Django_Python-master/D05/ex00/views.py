# coding : utf8

from django.shortcuts import render, HttpResponse
import psycopg2

# Create your views here.
def init(request):
	try:
		conn = psycopg2.connect(
			database = 'formationdjango',
			host = 'localhost',
			user = 'djangouser',
			password = 'secret'
			)
		
		curr = conn.cursor()

		curr.execute(""" CREATE TABLE IF NOT EXISTS ex00_movies (
			episode_nb serial PRIMARY KEY, 
			title varchar(64) NOT NULL,
			opening_crawl text,
			director varchar(32) NOT NULL,
			producer varchar(128) NOT NULL,
			release_date date NOT NULL
			)
			""")
		conn.commit()
		conn.close()
	except psycopg2.Error as e:
		print('Erreur : ', e.pgerror)
		retStr = 'Erreur :' + str(e.pgerror).replace('\n', '<br />')
		return HttpResponse(retStr)
	return HttpResponse('OK')
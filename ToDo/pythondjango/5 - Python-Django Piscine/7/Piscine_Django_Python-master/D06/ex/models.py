from django.db import models

# Create your models here.


class Upvote(models.Model):
	""" on cree une instance de cette classe pour representer un upvote
		et on la supprime si on enleve le vote """
	voter = models.CharField(max_length=150)


class Downvote(models.Model):
	""" on cree une instance de cette classe pour representer un downvote
		et on la supprime si on enleve le vote """
	voter = models.CharField(max_length=150)

class Tip(models.Model):
	contenu = models.TextField()
	auteur = models.CharField(max_length = 150)
	date = models.DateTimeField(auto_now_add=True) # la date sera inserre automatiquement
	upvote = models.ManyToManyField(Upvote)
	downvote = models.ManyToManyField(Downvote)

	def upvoteForUser(self, username):
		votes = self.upvote.all()
		# si l'un des votes a pour valeur de champ voter identique au user en cours, le supprimer
		found = False
		for index in votes:
			if index.voter == username:
				found = True
				index.delete()
				break
		# sinon creer le Upvote, le relier au tip et supprimer l'eventuel downvote
		if not found:
			newvote = Upvote(voter=username)
			newvote.save()
			self.upvote.add(newvote)
			
			downvotes = self.downvote.all()
			for index in downvotes:
				if index.voter == username:
					index.delete()
					break
			self.save()


	def downvoteForUser(self, username):
		votes = self.downvote.all()
		# si l'un des votes a pour valeur de champ voter identique au user en cours, le supprimer
		found = False
		for index in votes:
			if index.voter == username:
				found = True
				index.delete()
				break
		# sinon creer le Downvote, le relier au tip et supprimer l'eventuel Upvote
		if not found:
			newvote = Downvote(voter=username)
			newvote.save()
			self.downvote.add(newvote)
			
			upvotes = self.upvote.all()
			for index in upvotes:
				if index.voter == username:
					index.delete()
					break
			self.save()

	def __str__(self):
		return str(self.date) + ' ' + self.contenu + ' par ' + self.auteur \
			+ ' upvotes : ' + str(len(self.upvote.all())) \
			+ ' downvotes : ' + str(len(self.downvote.all()))


//
//  articleManager.swift
//  mafernan2018
//
//  Created by Marco FERNANDES on 2018/10/11.
//

import Foundation
import CoreData

// allows to use it publically when imported as a library in other projects

public final class ArticleManager {
    
    //    newArticle that allow us to create a new article and returns it.
    //    • getAllArticles that returns every stored articles.
    //    • getArticles(withLang lang: String) that returns every stored articles in a specific
    //    language.
    //    • getArticles(containString str: String) that returns every articles containing
    //    the following string give as a parameter.
    //    • removeArticle(article : Article) that removes an article.
    //    • save that saves every modification
    
    private(set) lazy var managedObjectContext: NSManagedObjectContext = {
        let managedObjectContext = NSManagedObjectContext(concurrencyType: .mainQueueConcurrencyType)
        
        managedObjectContext.persistentStoreCoordinator = self.persistentStoreCoordinator
        
        return managedObjectContext
    }()
    
    private lazy var managedObjectModel: NSManagedObjectModel = {
        guard let modelURL = Bundle.init(for: Article.self).url(forResource: "article", withExtension: "momd") else {
            fatalError("Unable to Find Data Model")
        }
        
        guard let managedObjectModel = NSManagedObjectModel(contentsOf: modelURL) else {
            fatalError("Unable to Load Data Model")
        }
        
        return managedObjectModel
    }()
    
    private lazy var persistentStoreCoordinator: NSPersistentStoreCoordinator = {
        let persistentStoreCoordinator = NSPersistentStoreCoordinator(managedObjectModel: self.managedObjectModel)
        
        let fileManager = FileManager.default
        let storeName = "article.sqlite"
        
        let documentsDirectoryURL = fileManager.urls(for: .documentDirectory, in: .userDomainMask)[0]
        
        let persistentStoreURL = documentsDirectoryURL.appendingPathComponent(storeName)
        
        do {
            try persistentStoreCoordinator.addPersistentStore(ofType: NSSQLiteStoreType,
                                                              configurationName: nil,
                                                              at: persistentStoreURL,
                                                              options: nil)
        } catch {
            fatalError("Unable to Load Persistent Store")
        }
        
        return persistentStoreCoordinator
    }()
    
    public init() {
        
    }
    
    var article : Article?
    
    // create a new article
    public func newArticle() -> Article
    {
        let context = self.managedObjectContext
        let temp = NSEntityDescription.entity(forEntityName: "Article", in: context)
        self.article = Article.init(entity: temp!, insertInto: context)
        self.article?.creationDate = Date()
        self.article?.modificationDate = Date()
        return self.article!
    }
    
    public func getAllArticles() -> [Article] {
        // create the context
        let managedContext = self.managedObjectContext
        
        // prepare request to fetch type of NSFetchRequest
        let fetchRequest = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        
        // fetch all the articles
        let emptyArticles: [Article] = []
        do {
            let result = try managedContext.fetch(fetchRequest)
            let articles = result as! [Article]
            return articles
        } catch {
            print("Failed to get articles")
        }
        return emptyArticles
    }
    
    public func getArticles(lang: String) -> [Article] {
        // create the context
        let managedContext = self.managedObjectContext
        
        // prepare request to fetch type of NSFetchRequest
        let fetchRequest = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        fetchRequest.predicate =  NSPredicate(format: "language = %@", lang)
        
        // fetch all the articles
        let emptyArticles: [Article] = []
        do {
            let result = try managedContext.fetch(fetchRequest)
            let articles = result as! [Article]
            return articles
        } catch {
            print("Failed to get articles")
        }
        return emptyArticles
    }
    
    // get all articles
    public func getArticles(str: String) -> [Article] {
        // create the context
        let managedContext = self.managedObjectContext
        
        // prepare request to fetch type of NSFetchRequest
        let fetchRequest = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        
        // fetch all the articles
        let emptyArticles: [Article] = []
        do {
            let result = try managedContext.fetch(fetchRequest)
            let articles = result as! [Article]
            return articles
        } catch {
            print("Failed to get articles")
        }
        var articlesTitle: [Article] = []
        for data in emptyArticles {
            if data.title == str {
                articlesTitle.append(data)
            }
        }
        return articlesTitle
    }
    
    // remove the article
    public func removeArticle(article: Article) {
        // create the context
        let managedContext = self.managedObjectContext
        
        // prepare request to fetch type of NSFetchRequest
        let fetchRequest = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        
        // fetch all the articles
        do {
            let result = try managedContext.fetch(fetchRequest)
            for data in result as! [NSManagedObject] {
                if data == article {
                    managedContext.delete(article)
                }
            }
        } catch {
            print("Failed to delete article")
        }
    }
    
    // save the article
    public func save() {
        self.article?.setValue(self.article?.creationDate, forKey: "creationDate")
        self.article?.setValue(Date(), forKey: "modificationDate")
        self.article?.setValue(self.article?.title, forKey: "title")
        self.article?.setValue(self.article?.image, forKey: "image")
        self.article?.setValue(self.article?.content, forKey: "content")
        self.article?.setValue(self.article?.language, forKey: "language")
        if managedObjectContext.hasChanges {
            do {
                try managedObjectContext.save()
            } catch {
                    print("Failed to save")
                }
            }
        }
}




























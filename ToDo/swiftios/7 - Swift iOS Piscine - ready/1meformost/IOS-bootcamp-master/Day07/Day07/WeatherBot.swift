//
//  WeatherBot.swift
//  Day07
//
//  Created by Marco FERNANDES on 2018/10/10.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import Foundation

import RecastAI
import ForecastIO

let recastAIToken = "183c293c207cd2db37b41efcddac2060";
let forecastIOToken = "21eaac84e6ce9fba6cd103add50919ea";
let language = "en";

protocol WeatherBotDelegate: class {
    var responseText: String? { get set };
}

// We create a weatherBot class
class WeatherBot {
    var delegate: WeatherBotDelegate?;
    var bot: RecastAIClient!;
    var darkSky: DarkSkyClient!;
    var location: (String, Double, Double)?;
    
    // here we call the request
    func handleRequest(request: String) {
        self.delegate!.responseText = "Will check what I can find out for you";
        self.bot?.textRequest(request, successHandler: handleRecastAIResponse, failureHandle: handleRecastAIError);
    }
    
    // here we will handle what we do with the request
    // It's the same as in the view Controller, will eventually clean this code up to use only this class 😅
    func handleRecastAIResponse(_ response: Response) {
        let intent = response.intent()
        if (intent?.description) != nil {
            if let location = response.get(entity: "location") {
                if let datetime = response.get(entity: "datetime") {
                    let dateFormatter = DateFormatter()
                    dateFormatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ssZ"
                    dateFormatter.locale = NSLocale(localeIdentifier: "en_US_POSIX") as Locale?
                    let date = dateFormatter.date(from: datetime["iso"] as! String)!
                    darkSky.getForecast(latitude: location["lat"] as! Double, longitude: location["lng"] as! Double, time: date, completion: forecastResult)
                } else if let dateduration = response.get(entity: "duration") {
                    var dateComponent = DateComponents()
                    dateComponent.second = dateduration["seconds"] as? Int
                    let futureDate = Calendar.current.date(byAdding: dateComponent, to: Date())
                    darkSky.getForecast(latitude: location["lat"] as! Double, longitude: location["lng"] as! Double, time: futureDate!, completion: forecastResult)
                } else {
                    darkSky.getForecast(latitude: location["lat"] as! Double, longitude: location["lng"] as! Double, completion: forecastResult)
                }
            } else {
                self.delegate!.responseText = "Sorry, I could not pinpoint a location 😭";
            }
        } else {
            self.delegate!.responseText = "Not sure what you asked for";
        }
    }
    
    func forecastResult(res: Result<Forecast>) -> Void {
        switch res {
        case .success(let currentForecast, _):
            print("Succes: Was able to get forecast information")
            DispatchQueue.main.async {
                self.delegate!.responseText = "The wheather is " + currentForecast.currently!.summary!;
            }
            break
        case .failure( _):
            self.delegate!.responseText = "Sorry, I could not fina a weather summary for you 😭";
            break
        }
    }
    
    // throw error if unable to reach Recast or find any info based on the intent
    func handleRecastAIError(_ error: Error) {
        self.delegate!.responseText = "Sorry, I seem unable to find anything. Can you be more clear?";
        print(error);
    }
    
    // we connect to the bots here when we init the class
    init(delegate: WeatherBotDelegate) {
        self.bot = RecastAIClient(token: recastAIToken, language: language);
        self.darkSky = DarkSkyClient(apiKey: forecastIOToken);
        self.delegate = delegate
    }
}

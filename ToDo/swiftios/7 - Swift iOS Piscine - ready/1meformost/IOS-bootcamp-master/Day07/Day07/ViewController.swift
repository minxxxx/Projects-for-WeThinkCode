//
//  ViewController.swift
//  Day07
//
//  Created by Marco FERNANDES on 2018/10/10.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit
import ForecastIO
import RecastAI
import Speech


class ViewController: UIViewController, SFSpeechRecognizerDelegate {

    @IBOutlet weak var inputField: UITextField!
    @IBOutlet weak var resultsField: UILabel!
    @IBOutlet weak var siriButton: UIButton!
    
    // variables needed for speech recognition
    private let speechRecognizer = SFSpeechRecognizer(locale: Locale.init(identifier: "en-US"));
    private var recognitionRequest: SFSpeechAudioBufferRecognitionRequest?
    private var recognitionTask: SFSpeechRecognitionTask?
    private let audioEngine = AVAudioEngine()
    
    // make it global to the class to use it later
    var bot : RecastAIClient?
    var client : DarkSkyClient?
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // get the Recast and Forecast token authorized
        self.bot = RecastAIClient(token : "183c293c207cd2db37b41efcddac2060", language: "en")
        self.client = DarkSkyClient(apiKey: "21eaac84e6ce9fba6cd103add50919ea")
        // ask for speech permission
        speechInit()
    }
    
    func speechInit() {
        speechRecognizer?.delegate = self
        SFSpeechRecognizer.requestAuthorization(handleSpeechStatus)
    }
    
    func handleSpeechStatus(_ status: SFSpeechRecognizerAuthorizationStatus) {
        DispatchQueue.main.sync {
            siriButton.isEnabled = (status == .authorized);
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    // when to call RecastAI request that get passed to ForecastIO
    @IBAction func requestButton(_ sender: Any) {
        if inputField.text == "" {
            resultsField.text = "Empty Field Requested"
        } else {
            makeRequest(text: inputField.text!)
        }
    }
    
    // start recording when siri button tapped
    @IBAction func siriButton(_ sender: Any) {
        if (audioEngine.isRunning) {
            stopRecording();
        } else {
            startRecording();
        }
    }
    
    // start recording with Siri
    func startRecording() {
        if (recognitionTask != nil) {
            recognitionTask?.cancel()
            recognitionTask = nil
        }
        
        // setup audio session
        let audioSession = AVAudioSession.sharedInstance();
        do {
            try audioSession.setCategory(AVAudioSessionCategoryRecord)
            try audioSession.setMode(AVAudioSessionModeMeasurement)
            try audioSession.setActive(true, with: .notifyOthersOnDeactivation)
        } catch {
            print("audioSession properties weren't set because of an error.")
        }
        recognitionRequest = SFSpeechAudioBufferRecognitionRequest()
        let inputNode = audioEngine.inputNode;
        guard let recognitionRequest = recognitionRequest else {
            fatalError("Unable to create an SFSpeechAudioBufferRecognitionRequest object")
        }
        recognitionRequest.shouldReportPartialResults = true;
        recognitionTask = speechRecognizer!.recognitionTask(with: recognitionRequest, resultHandler: {(result, error) in
            var isFinal = false
            
            if (result != nil) {
                self.inputField.text = result?.bestTranscription.formattedString;
                isFinal = (result?.isFinal)!;
            }
            if (error != nil || isFinal) {
                self.audioEngine.stop();
                inputNode.removeTap(onBus: 0);
                self.recognitionRequest = nil;
                self.recognitionTask = nil;
                //self.siriButton.isEnabled = true;
            }
        });
        let recordingFormat = inputNode.outputFormat(forBus: 0)
        inputNode.installTap(onBus: 0, bufferSize: 1024, format: recordingFormat) { (buffer, when) in
            self.recognitionRequest?.append(buffer)
        }
        audioEngine.prepare()
        do {
            try audioEngine.start()
        } catch {
            print("audioEngine couldn't start because of an error.")
        }
        self.resultsField.text = "Say something, I'm listening!"
        //self.siriButton.setTitle("\u{f131}", for: .normal);
    }
    
    
    // stop recording
    func stopRecording() {
        audioEngine.stop();
        audioEngine.inputNode.removeTap(onBus: 0);
        recognitionRequest?.endAudio();
        siriButton.setTitle("\u{f130}", for: .normal)
    }
    
    // Make text request to Recast.AI API
    func makeRequest(text: String)
    {
        //Call makeRequest with string parameter to make a text request
        self.bot?.textRequest(text, successHandler: response, failureHandle: error)
    }
    
    // What todo with Recast response
    func response(_ response: Response) -> Void {
        print("Success: Found a response from RecastAI")
        print(response.description)
        let intent = response.intent()
        if (intent?.description) != nil {
            if let location = response.get(entity: "location") {
                if let datetime = response.get(entity: "datetime") {
                    let dateFormatter = DateFormatter()
                    dateFormatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ssZ"
                    dateFormatter.locale = NSLocale(localeIdentifier: "en_US_POSIX") as Locale?
                    let date = dateFormatter.date(from: datetime["iso"] as! String)!
                    self.client?.getForecast(latitude: location["lat"] as! Double, longitude: location["lng"] as! Double, time: date, completion: forecastResult)
                } else if let dateduration = response.get(entity: "duration") {
                    var dateComponent = DateComponents()
                    dateComponent.second = dateduration["seconds"] as? Int
                    let futureDate = Calendar.current.date(byAdding: dateComponent, to: Date())
                    self.client?.getForecast(latitude: location["lat"] as! Double, longitude: location["lng"] as! Double, time: futureDate!, completion: forecastResult)
                } else {
                    self.client?.getForecast(latitude: location["lat"] as! Double, longitude: location["lng"] as! Double, completion: forecastResult)
                }
            } else {
                resultsField.text = "Error"
                print("Location not found")
            }
        } else {
            resultsField.text = "Error"
            print("Intent not found, be more specific")
        }
    }
    
    // what todo with Recast response if it returns an error
    func error(_ error: Error) -> Void {
        print("failed to get response")
        resultsField.text = "Error"
    }
    
    // What todo ForecastIO returns a result or empty
    func forecastResult(res: Result<Forecast>) -> Void {
        switch res {
        case .success(let currentForecast, _):
            print("Succes: Was able to get forecast information")
            DispatchQueue.main.async {
                self.resultsField.text = currentForecast.currently?.summary
            }
            break
        case .failure( _):
            resultsField.text = "Error"
            print("Error: Could not get Forcast weather data")
            break
        }
    }
}


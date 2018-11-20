//
//  IRMnemonic.h
//  IrohaCrypto
//
//  Created by Ruslan Rezin on 15/11/2018.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, IRMnemonicStrength) {
    IREntropy128 = 128,
    IREntropy160 = 160,
    IREntropy192 = 192,
    IREntropy224 = 224,
    IREntropy256 = 256,
    IREntropy288 = 288,
    IREntropy320 = 320
};

typedef NS_ENUM(NSUInteger, IRMnemonicError) {
    IRRandomGenerationFailed,
    IRInvalidEntropyLength,
    IRInvalidNumberOfWords,
    IRWordNotFound,
    IRChecksumFailed
};

typedef NS_ENUM(NSUInteger, IRMnemonicLanguage) {
    IREnglish
};

@protocol IRMnemonicProtocol <NSObject>

- (nonnull NSData*)entropy;
- (nonnull NSString*)wordAtIndex:(NSUInteger)index;
- (NSUInteger)numberOfWords;
- (nonnull NSArray<NSString*>*)allWords;
- (nonnull NSString *)toString;

@end

@protocol IRMnemonicCreatorProtocol <NSObject>

- (nullable id<IRMnemonicProtocol>)randomMnemonic:(IRMnemonicStrength)strength error:(NSError**)error;
- (nullable id<IRMnemonicProtocol>)mnemonicFromEntropy:(nonnull NSData*)entropy error:(NSError**)error;
- (nullable id<IRMnemonicProtocol>)mnemonicFromList:(nonnull NSArray<NSString*> *)wordList error:(NSError**)error;

@end

/**
 *  Implementation of https://github.com/bitcoin/bips/blob/master/bip-0039.mediawiki
 */

@interface IRBIP39MnemonicCreator : NSObject<IRMnemonicCreatorProtocol>

@property(readonly, nonatomic)IRMnemonicLanguage language;

+ (instancetype)defaultCreator;

- (nonnull instancetype)initWithLanguage:(IRMnemonicLanguage)language;

@end
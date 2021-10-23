#include"AssetManager.h"
/// <summary>
/// コンストラクタ
/// </summary>
AssetManager::AssetManager()
{
}
/// <summary>
/// デストラクタ
/// </summary>
AssetManager::~AssetManager()
{
}

/// <summary>
/// メッシュの取得
/// </summary>
/// <param name="meshFileName">
/// メッシュのパス、ファイル名
/// </param>
/// <returns>
/// メッシュが今まで読み込まれたことのないものであればmapに新規作成、
/// そうでなければ既存のパスのメッシュをコピーしてそのハンドルを返す
/// </returns>
int AssetManager::GetMesh(std::string meshFileName)
{
	int meshId=0;
	if (mMeshMap.find(meshFileName)==mMeshMap.end())
	{
		meshId = MV1LoadModel(meshFileName.c_str());
		if (meshId == -1)
		{
			return meshId;
		}
		mMeshMap.emplace(meshFileName, meshId);
	}

	meshId = MV1DuplicateModel(mMeshMap[meshFileName]);
	mDuplicatesMesh.push_back(meshId);
	return meshId;

}
/// <summary>
/// アニメーションの取得
/// </summary>
/// <param name="meshFileName">
/// アニメーションのパス、ファイル名
/// </param>
/// <returns>
/// アニメーションが今まで読み込まれたことのないものであればmapに新規作成、
/// そうでなければ既存のパスのアニメーションをコピーしてそのハンドルを返す
/// </returns>
int AssetManager::GetAnimation(std::string animationFileName)
{
	int animId;
	if (mAnimMap.find(animationFileName)==mAnimMap.end())
	{
		animId = MV1LoadModel(animationFileName.c_str());
		if (animId == -1)
		{
			return animId;
		}
		mAnimMap.emplace(animationFileName, animId);
	}
	



	return mAnimMap[animationFileName];
}
/// <summary>
/// 引数のメッシュの開放
/// </summary>
/// <param name="meshID">
/// 開放するメッシュのID、インデックス
/// </param>
void AssetManager::RemoveMesh(int meshID)
{
	/*for (auto  itr = mDuplicatesMesh.begin(); itr!=mDuplicatesMesh.end();)
	{
		if (*itr==meshID)
		{
			MV1DeleteModel(meshID);
			mDuplicatesMesh.erase(itr);
			break;
		}
		else
		{
			itr++;
		}
	}*/
	auto result = find(mDuplicatesMesh.begin(), mDuplicatesMesh.end(), meshID);
	if (result!=mDuplicatesMesh.end())
	{

		MV1DeleteModel(*result);
		mDuplicatesMesh.erase(result);
		iter_swap(result, mDuplicatesMesh.end()-1);
		mDuplicatesMesh.pop_back();
	}
}
/// <summary>
/// すべてのメッシュ、アニメーションの開放
/// </summary>
void AssetManager::RemoveAll()
{
	
	for (auto itr = mDuplicatesMesh.begin(); itr !=mDuplicatesMesh.end();)
	{
		MV1DeleteModel(*itr);
		itr++;
	}
	mDuplicatesMesh.clear();
	for (auto itr = mAnimMap.begin(); itr !=mAnimMap.end(); ++itr)
	{
		MV1DeleteModel(itr->second);
	}
	for (auto itr = mMeshMap.begin(); itr !=mMeshMap.end(); ++itr)
	{
		MV1DeleteModel(itr->second);
	}
	mAnimMap.clear();
	mMeshMap.clear();
}

#include"AssetManager.h"
/// <summary>
/// �R���X�g���N�^
/// </summary>
AssetManager::AssetManager()
{
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
AssetManager::~AssetManager()
{
}

/// <summary>
/// ���b�V���̎擾
/// </summary>
/// <param name="meshFileName">
/// ���b�V���̃p�X�A�t�@�C����
/// </param>
/// <returns>
/// ���b�V�������܂œǂݍ��܂ꂽ���Ƃ̂Ȃ����̂ł����map�ɐV�K�쐬�A
/// �����łȂ���Ί����̃p�X�̃��b�V�����R�s�[���Ă��̃n���h����Ԃ�
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
/// �A�j���[�V�����̎擾
/// </summary>
/// <param name="meshFileName">
/// �A�j���[�V�����̃p�X�A�t�@�C����
/// </param>
/// <returns>
/// �A�j���[�V���������܂œǂݍ��܂ꂽ���Ƃ̂Ȃ����̂ł����map�ɐV�K�쐬�A
/// �����łȂ���Ί����̃p�X�̃A�j���[�V�������R�s�[���Ă��̃n���h����Ԃ�
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
/// �����̃��b�V���̊J��
/// </summary>
/// <param name="meshID">
/// �J�����郁�b�V����ID�A�C���f�b�N�X
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
/// ���ׂẴ��b�V���A�A�j���[�V�����̊J��
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
